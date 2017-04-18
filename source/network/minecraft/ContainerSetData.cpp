#include "ContainerSetData.h"

#include "MinecraftPackets.h"

ContainerSetData::ContainerSetData() : DataPacket(16) {
	windowID = 0x00;
	property = 0;
	value = 0;
}

void ContainerSetData::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ContainerSetData));
	putByte(windowID);
	putVarUInt(property);
	putVarUInt(value);
}