#include "ContainerClose.h"

#include "MinecraftPackets.h"

ContainerClose::ContainerClose() :DataPacket(2) {
	this->windowID = 0x00;
}

void ContainerClose::decode() {
	++this->position; // Skip Packet ID;
	this->windowID = this->getByte();
}

void ContainerClose::encode() {
	this->putByte((uint8)MinecraftPackets::ContainerClose);
	this->putByte(this->windowID);
}