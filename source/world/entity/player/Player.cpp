#include "Player.h"

#include <algorithm>

#include "Server.h"
#include "scheduler/CallbackTask.h"
#include "network/minecraft/AdventureSettings.h"
#include "network/minecraft/Batch.h"
#include "network/minecraft/ChunkRadiusUpdated.h"
#include "network/minecraft/Disconnect.h"
#include "network/minecraft/FullChunkData.h"
#include "network/minecraft/Login.h"
#include "network/minecraft/MinecraftPackets.h"
#include "network/minecraft/PlayStatus.h"
#include "network/minecraft/RequestChunkData.h"
#include "network/minecraft/ResourcePackClientResponse.h"
#include "network/minecraft/ResourcePacksInfo.h"
#include "network/minecraft/ResourcePackStack.h"
#include "network/minecraft/Respawn.h"
#include "network/minecraft/StartGame.h"
#include "network/raknet/ConnectionAccepted.h"
#include "network/raknet/ConnectionRequest.h"
#include "network/raknet/Ping.h"
#include "network/raknet/Pong.h"
#include "network/raknet/RaknetPackets.h"

Player::Player(Server* server, const std::string& ip, uint16 port, int64 clientID, int16 mtuSize) : RakLib::Session(std::move(ip), port, clientID, mtuSize) {
	this->server = server;
	this->username = this->lowerUserName = "Steve";
	this->spawnPosition = Vector3f(0.0f, 8.0f, 0.0f);

	this->server->getScheduler()->addTask(new CallbackTask(std::function<void()>(std::bind(&Player::update, this)), 10, -1));
}

void Player::update() {
	Session::update();
	// TODO
}

void Player::disconnect(const std::string& reason) {
	auto packet = std::make_unique<Disconnect>(reason);
	packet->encode();

	this->addDataPacket(std::move(packet), QueuePriority::IMMEDIATE);
	this->server->getLogger()->notice("%s (%s:%u) connection have been terminated. Reason: %s", this->username.c_str(), this->ip.c_str(), this->port, reason.c_str());
	this->server->removeSession(this->ip, this->port);
}

void Player::handleDataPacket(std::unique_ptr<RakLib::Packet> packet) {
	uint8 packetID = packet->getBuffer()[0];
	switch((RaknetPacket)packetID) {
	case RaknetPacket::PING:
	{
		Ping ping(std::move(packet));
		ping.decode();

		auto pong = std::make_unique<Pong>(ping.pingID);
		pong->encode();

		this->addToQueue(std::move(pong), QueuePriority::IMMEDIATE);
	}
	break;

	case RaknetPacket::CONNECTION_REQUEST:
	{
		ConnectionRequest connectionRequest(std::move(packet));
		connectionRequest.decode();

		auto connectionAccepted = std::make_unique<ConnectionAccepted>(this->ip, this->port, connectionRequest.sendPing, connectionRequest.sendPing * 100ULL);
		connectionAccepted->encode();

		this->addToQueue(std::move(connectionAccepted), QueuePriority::IMMEDIATE);
	}
	break;

	case RaknetPacket::WRAPPER:
	{
		packet->setPosition(1); // Skip Wrapper ID;
		uint32 realPacketSize = packet->getLength() - packet->getPosition();
		this->handleGamePacket(std::make_unique<RakLib::Packet>(packet->getByte(realPacketSize), realPacketSize));
	}
	break;

	default:
		this->server->getLogger()->debug("HandleDataPacket Packet(0x%02X, %u)", packetID, packet->getLength());
		break;
	}
}

void Player::handleGamePacket(std::unique_ptr<RakLib::Packet> packet) {
	uint8 packetID = packet->getBuffer()[0];
	switch ((MinecraftPackets)packetID) {
	case MinecraftPackets::Login:
	{
		Login login(std::move(packet));
		login.decode();

		if (login.protocol != NETWORK_PROTOCOL) {
			if (login.protocol < NETWORK_PROTOCOL) {
				this->disconnect("Wrong Protocol: Client is outdated.");
				return;
			}

			if (login.protocol > NETWORK_PROTOCOL) {
				this->disconnect("Wrong Protocol: Server is outdated.");
				return;
			}
		}

		this->server->getLogger()->info("%s have logged in", login.displayName.c_str());
		this->lowerUserName = this->username = std::move(login.displayName);

		std::transform(this->username.begin(), this->username.end(), this->lowerUserName.begin(), ::tolower);

		auto playStatus = std::make_unique<PlayStatus>(PlayStatus::STATUS::LOGIN_SUCCESS);
		playStatus->encode();
		this->addDataPacket(std::move(playStatus), QueuePriority::IMMEDIATE);

		// Post Login Stuff

		auto resourcePacksInfo = std::make_unique<ResourcePacksInfo>();
		resourcePacksInfo->encode();
		this->addDataPacket(std::move(resourcePacksInfo), QueuePriority::IMMEDIATE);
	}
	break;

	case MinecraftPackets::Batch:
	{
		Batch batch(std::move(packet));
		batch.decode();

		for (auto& batchedPacket : batch.packets) {
			if (batchedPacket->getBuffer()[0] == (uint8)MinecraftPackets::Batch) {
				this->server->getLogger()->fatal("BatchPacket inside another BatchPacket");
			}

			this->handleGamePacket(std::move(batchedPacket));
		}
	}
	break;

	case MinecraftPackets::ResourcePackClientResponse:
	{
		ResourcePackClientResponse clientResponse(std::move(packet));
		clientResponse.decode();

		if (clientResponse.status == ResourcePackClientResponse::HaveAllPacks) {
			auto resoucePackStack = std::make_unique<ResourcePackStack>();
			resoucePackStack->encode();

			this->addDataPacket(std::move(resoucePackStack), QueuePriority::IMMEDIATE);
		} else if (clientResponse.status == ResourcePackClientResponse::Completed) {
			this->postLogin();
		}
	}
	break;

	case MinecraftPackets::RequestChunkRadius:
	{
		RequestChunkData requestChunk(std::move(packet));
		requestChunk.decode();

		auto chunkRadiusUpdate = std::make_unique<ChunkRadiusUpdated>(requestChunk.radius);
		chunkRadiusUpdate->encode();
		this->addDataPacket(std::move(chunkRadiusUpdate), QueuePriority::IMMEDIATE);

		uint8* chunkData;
		uint32 chunkDataSize;
		std::tie(chunkData, chunkDataSize) = this->server->getLevel()->getChunk(0, 0)->serialize();
		
		for (int32 x = -requestChunk.radius; x <= requestChunk.radius; ++x) {
			for (int32 z = -requestChunk.radius; z <= requestChunk.radius; ++z) {
				auto fullChunkData = std::make_unique<FullChunkData>(x, z, chunkData, chunkDataSize);
				fullChunkData->encode();

				auto batchPacket = std::make_unique<Batch>();
				batchPacket->packets.push_back(std::move(fullChunkData));
				batchPacket->encode();

				this->addDataPacket(std::move(batchPacket), QueuePriority::IMMEDIATE);
			}
		}

		delete[] chunkData;

		auto respawn = std::make_unique<Respawn>();
		respawn->spawnPosition = this->spawnPosition;
		respawn->encode();
		this->addDataPacket(std::move(respawn), QueuePriority::IMMEDIATE);

		auto playStatus = std::make_unique<PlayStatus>(PlayStatus::STATUS::SPAWN);
		playStatus->encode();
		this->addDataPacket(std::move(playStatus), QueuePriority::IMMEDIATE);
	}
	break;

	default:
		this->server->getLogger()->debug("HandleGamePacket Packet(0x%02X, %u)", packetID, packet->getLength());
	break;
	}
}

void Player::addDataPacket(std::unique_ptr<RakLib::DataPacket>&& packet, QueuePriority priority) {
	std::unique_ptr<RakLib::DataPacket> dataPacket = std::make_unique<RakLib::DataPacket>(packet->getLength() + 1);
	dataPacket->putByte((uint8)RaknetPacket::WRAPPER);
	dataPacket->putByte(packet->getBuffer(), packet->getLength());
	this->addToQueue(std::move(dataPacket), priority);
}

void Player::sendPacket(RakLib::Packet& packet) { 
	packet.ip = this->ip;
	packet.port = this->port;

	this->server->sendPacket(packet);
}

void Player::postLogin() {
	auto startGame = std::make_unique<StartGame>(this->id, this->spawnPosition, "");
	startGame->encode();
	this->addDataPacket(std::move(startGame), QueuePriority::IMMEDIATE);

	auto settings = std::make_unique<AdventureSettings>(AdventureSettings::PERMISSIONS::NORMAL, 0x0000012E);
	settings->encode();
	this->addDataPacket(std::move(settings), QueuePriority::IMMEDIATE);
}