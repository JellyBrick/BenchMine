#include "SetEntityMotion.h"

#include "MinecraftPackets.h"

SetEntityMotion::SetEntityMotion() : DataPacket(32) {
	entityID = 0;
}

void SetEntityMotion::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::SetEntityMotion));
	putVarULong(entityID);
	Vector3f::serialize(entityMotion, *this);
}