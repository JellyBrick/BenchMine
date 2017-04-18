#include "ContainerClose.h"

#include "MinecraftPackets.h"

ContainerClose::ContainerClose() :DataPacket(2) {
	windowID = 0x00;
}

void ContainerClose::decode() {
	++position; // Skip Packet ID;
	windowID = getByte();
}

void ContainerClose::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ContainerClose));
	putByte(windowID);
}