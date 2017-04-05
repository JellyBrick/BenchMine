#include "SetEntityLink.h"

#include "MinecraftPackets.h"

SetEntityLink::SetEntityLink() : DataPacket(16) {
	this->from = 0;
	this->to = 0;
	this->type = 0x00;
}

void SetEntityLink::encode() {
	this->putByte((uint8)MinecraftPackets::SetEntityLink);
	this->putVarULong(this->from);
	this->putVarULong(this->to);
	this->putByte(this->type);
}