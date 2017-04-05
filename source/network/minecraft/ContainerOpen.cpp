#include "ContainerOpen.h"

#include "MinecraftPackets.h"

ContainerOpen::ContainerOpen() : DataPacket(32) {
	this->windowsID = 0x00;
	this->type = 0x00;
	this->slots = 0;
	this->entityID = 0;
}

void ContainerOpen::encode() {
	this->putByte((uint8)MinecraftPackets::ContainerOpen);
	this->putByte(this->windowsID);
	this->putByte(this->type);
	this->putVarUInt(this->slots);
	Vector3i::serialize(this->containerPosition, *this);
	this->putVarULong(this->entityID);
}