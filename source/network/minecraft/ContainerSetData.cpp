#include "ContainerSetData.h"

#include "MinecraftPackets.h"

ContainerSetData::ContainerSetData() : DataPacket(16) {
	this->windowID = 0x00;
	this->property = 0;
	this->value = 0;
}

void ContainerSetData::encode() {
	this->putByte((uint8)MinecraftPackets::ContainerSetData);
	this->putByte(this->windowID);
	this->putVarUInt(this->property);
	this->putVarUInt(this->value);
}