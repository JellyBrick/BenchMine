#include "MinecraftPackets.h"
#include "Ping.h"

Ping::Ping(Packet* pck) : DataPacket(pck) {
	this->pingID = 0;
}

Ping::Ping(int64 pingID) : DataPacket(9) {
	this->pingID = pingID;
}

void Ping::decode() {
	if (this->getByte() != MinecraftPackets::PING)
		return;

	this->pingID = this->getLong();
}

void Ping::encode() {
	this->putByte(MinecraftPackets::PING);
	this->putLong(this->pingID);
}