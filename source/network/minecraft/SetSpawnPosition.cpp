#include "SetSpawnPosition.h"

#include "MinecraftPackets.h"

SetSpawnPosition::SetSpawnPosition() : DataPacket(64) {
	this->unknown1 = 0;
	this->unknown2 = false;
}

void SetSpawnPosition::encode() {
	this->putByte((uint8)MinecraftPackets::SetSpawnPosition);
	this->putVarUInt(this->unknown1);
	Vector3i::serialize(this->spawnPosition, *this);
	this->putBool(this->unknown2);
}