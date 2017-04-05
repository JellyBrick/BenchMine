#include "Animate.h"

#include "MinecraftPackets.h"

Animate::Animate() : DataPacket(9) {
	this->action = 0;
	this->entityID = 0;
}

void Animate::encode() {
	this->putByte((uint8)MinecraftPackets::Animate);
	this->putVarUInt(this->action);
	this->putVarULong(this->entityID);
}