#include "ContainerOpen.h"

#include "MinecraftPackets.h"

ContainerOpen::ContainerOpen() : DataPacket(32) {
	windowsID = 0x00;
	type = 0x00;
	slots = 0;
	entityID = 0;
}

void ContainerOpen::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ContainerOpen));
	putByte(windowsID);
	putByte(type);
	putVarUInt(slots);
	Vector3i::serialize(containerPosition, *this);
	putVarULong(entityID);
}