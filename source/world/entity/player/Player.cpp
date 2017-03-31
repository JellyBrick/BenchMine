#include "Player.h"

#include <algorithm>

#include "Server.h"
#include "scheduler/CallbackTask.h"
#include "network/minecraft/AdventureSettings.h"
#include "network/minecraft/Disconnect.h"
#include "network/minecraft/Login.h"
#include "network/minecraft/MinecraftPackets.h"
#include "network/minecraft/PlayStatus.h"
#include "network/minecraft/StartGame.h"
#include "network/raknet/ConnectionAccepted.h"
#include "network/raknet/ConnectionRequest.h"
#include "network/raknet/Ping.h"
#include "network/raknet/Pong.h"
#include "network/raknet/RaknetPackets.h"

Player::Player(Server* server, const std::string& ip, uint16 port, int64 clientID, int16 mtuSize) : RakLib::Session(std::move(ip), port, clientID, mtuSize) {
	this->server = server;
	this->username = this->lowerUserName = "Steve";

	this->server->getScheduler()->addTask(new CallbackTask(std::function<void()>(std::bind(&Player::update, this)), 10, -1));
}

void Player::update() {
	Session::update();
	// TODO
}

void Player::disconnect(const std::string& reason) {
	auto packet = std::make_unique<Disconnect>(reason);
	packet->encode();

	this->addToQueue(std::move(packet), QueuePriority::IMMEDIATE);
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
		this->handleGamePacket(std::move(packet));
	break;

	default:
		this->server->getLogger()->debug("Packet(0x%02X, %u)", packetID, packet->getLength());
		break;
	}
}

void Player::handleGamePacket(std::unique_ptr<RakLib::Packet> packet) {
	uint8 packetID = packet->getBuffer()[1];
	this->server->getLogger()->debug("Packet Wrapped: 0x%02x", packetID);

	switch ((MinecraftPackets)packetID) {
	case MinecraftPackets::LOGIN:
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
		this->addToQueue(std::move(playStatus), QueuePriority::IMMEDIATE);

		// Post Login Stuff
		// TODO: Move to it's own method

		auto startGame = std::make_unique<StartGame>(this->id, Vector3f(0.0f, 4.0f, 0.0f), "");
		startGame->encode();
		this->addToQueue(std::move(startGame), QueuePriority::IMMEDIATE);

		auto settings = std::make_unique<AdventureSettings>(AdventureSettings::PERMISSIONS::NORMAL, 0x3FF);
		settings->encode();
		this->addToQueue(std::move(settings), QueuePriority::IMMEDIATE);
	}
	break;

	default:
		this->server->getLogger()->debug("Packet(0x%02X, %u)", packetID, packet->getLength());
		break;
	}
}

void Player::sendPacket(RakLib::Packet& packet) { 
	packet.ip = this->ip;
	packet.port = this->port;

	this->server->sendPacket(packet);
}