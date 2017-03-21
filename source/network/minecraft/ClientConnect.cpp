#include "ClientConnect.h"

#include <cassert>

#include "MinecraftPackets.h"

ClientConnect::ClientConnect(std::unique_ptr<Packet> packet) : DataPacket(std::move(packet)) {
	this->clientID = 0;
	this->sendPing = 0;
	this->useSecurity = false;
}

void ClientConnect::decode() {
	assert(this->getByte() == MinecraftPackets::CLIENT_CONNECT);

	this->clientID = this->getLong();
	this->sendPing = this->getLong();
	this->useSecurity = this->getBool();
}
