#include "Player.h"

#include <algorithm>

#include "Server.h"
#include "scheduler/CallbackTask.h"
#include "network/raknet/ConnectionAccepted.h"
#include "network/raknet/ConnectionRequest.h"
#include "network/raknet/Ping.h"
#include "network/raknet/Pong.h"
#include "network/raknet/RaknetPackets.h"

Player::Player(Server* server, const std::string& ip, uint16 port, int64 clientID, int16 mtuSize) : RakLib::Session(std::move(ip), port, clientID, mtuSize) {
	this->server = server;
	this->username = this->lowerUserName = "Steve";
	std::transform(this->lowerUserName.begin(), this->lowerUserName.end(), this->lowerUserName.begin(), ::tolower);

	this->server->getScheduler()->addTask(new CallbackTask(std::function<void()>(std::bind(&Player::update, this)), 10, -1));
}

void Player::close(const std::string& reason) {
	//TODO
}

void Player::handleDataPacket(std::unique_ptr<RakLib::DataPacket> packet) {
	uint8 packetID = packet->getBuffer()[0];
	this->server->getLogger()->debug("Packet ID: %02X Length: %u", packetID, packet->getLength());
	
	switch(packetID) {
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
	}
}

void Player::sendPacket(RakLib::Packet& packet) { 
	packet.ip = this->ip;
	packet.port = this->port;

	this->server->sendPacket(packet);
}