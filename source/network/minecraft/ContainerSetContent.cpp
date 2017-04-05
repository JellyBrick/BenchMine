#include "ContainerSetContent.h"

#include "MinecraftPackets.h"

//TODO: Do, when proper inventory system is implemented
ContainerSetContent::ContainerSetContent() : DataPacket(128) {
	this->windowID = 0x00;
}

void ContainerSetContent::decode() {
	++this->position;
	this->windowID = this->getByte();
}

void ContainerSetContent::encode() {
	this->putByte((uint8)MinecraftPackets::ContainerSetContent);
	this->putByte(this->windowID);
}