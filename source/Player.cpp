#include "Player.h"

#include <algorithm>

#include "Server.h"
#include "scheduler/CallbackTask.h"
#include "network/minecraft/ClientConnect.h"

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
	// TODO
}

void Player::sendPacket(const RakLib::Packet& packet) {
	this->server->sendPacket(packet);
}