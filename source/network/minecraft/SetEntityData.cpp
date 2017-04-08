#include "SetEntityData.h"

#include "MinecraftPackets.h"

SetEntityData::SetEntityData() : DataPacket(32) {
	entityID = 0;
}

void SetEntityData::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::SetEntityData));
	putVarULong(entityID);
	// EntityMetadata::serialize
}