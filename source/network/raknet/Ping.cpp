#include "Ping.h"

#include "RaknetPackets.h"

Ping::Ping(std::unique_ptr<Packet> packet) : DataPacket(std::move(packet)) {
	this->pingID = 0;
}

Ping::Ping(int64 pingID) : DataPacket(9) {
	this->pingID = pingID;
}

void Ping::decode() {
	if (this->getByte() != PING) {
		return;
	}

	this->pingID = this->getLong();
}

void Ping::encode() {
	this->putByte(PING);
	this->putLong(this->pingID);
}