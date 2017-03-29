#include "Ping.h"

#include "RaknetPackets.h"

Ping::Ping(std::unique_ptr<RakLib::Packet>&& packet) : DataPacket(std::move(packet)), pingID(0) {}

Ping::Ping(int64 pingID) : DataPacket(9) {
	this->pingID = pingID;
}

void Ping::decode() {
	if (this->getByte() != (uint8)RaknetPacket::PING) {
		return;
	}

	this->pingID = this->getLong();
}

void Ping::encode() {
	this->putByte((uint8)RaknetPacket::PING);
	this->putLong(this->pingID);
}