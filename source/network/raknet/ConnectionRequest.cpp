#include "ConnectionRequest.h"

#include <cassert>

#include "RaknetPackets.h"

ConnectionRequest::ConnectionRequest(std::unique_ptr<RakLib::Packet>&& packet) : DataPacket(std::move(packet)) {
	this->clientID = 0;
	this->sendPing = 0;
	this->useSecurity = false;
}

void ConnectionRequest::decode() {
	assert(this->getByte() == (uint8)RaknetPacket::CONNECTION_REQUEST);

	this->clientID = this->getLong();
	this->sendPing = this->getULong();
	this->useSecurity = this->getBool();
}
