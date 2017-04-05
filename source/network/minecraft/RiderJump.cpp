#include "RiderJump.h"

#include "MinecraftPackets.h"

RiderJump::RiderJump() : DataPacket(8) {
	this->unknown = 0;
}

void RiderJump::decode() {
	++this->position; // Skip Packet ID
	this->unknown = this->getVarUInt();
}

void RiderJump::encode() {
	this->putByte((uint8)MinecraftPackets::RiderJump);
	this->putVarUInt(this->unknown);
}