#include "ContainerSetContent.h"

#include "MinecraftPackets.h"

//TODO: Do, when proper inventory system is implemented
ContainerSetContent::ContainerSetContent() : DataPacket(128) {
	windowID = 0x00;
}

void ContainerSetContent::decode() {
	++position;
	windowID = getByte();
}

void ContainerSetContent::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ContainerSetContent));
	putByte(windowID);
}