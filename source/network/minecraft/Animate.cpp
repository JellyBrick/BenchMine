#include "Animate.h"

#include "MinecraftPackets.h"

Animate::Animate() : DataPacket(9) {
	action = 0;
	entityID = 0;
}

void Animate::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::Animate));
	putVarUInt(action);
	putVarULong(entityID);
}