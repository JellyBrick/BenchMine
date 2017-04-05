#include "SetEntityMotion.h"

#include "MinecraftPackets.h"

SetEntityMotion::SetEntityMotion() : DataPacket(32) {
	this->entityID = 0;
}

void SetEntityMotion::encode() {
	this->putByte((uint8)MinecraftPackets::SetEntityMotion);
	this->putVarULong(this->entityID);
	Vector3f::serialize(this->entityMotion, *this);
}