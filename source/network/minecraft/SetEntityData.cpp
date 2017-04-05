#include "SetEntityData.h"

#include "MinecraftPackets.h"

SetEntityData::SetEntityData() : DataPacket(32) {
	this->entityID = 0;
}

void SetEntityData::encode() {
	this->putByte((uint8)MinecraftPackets::SetEntityData);
	this->putVarULong(this->entityID);
	// EntityMetadata::serialize
}