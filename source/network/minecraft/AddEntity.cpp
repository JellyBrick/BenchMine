#include "AddEntity.h"

#include "MinecraftPackets.h"

// TODO: Remove placeholder size
AddEntity::AddEntity() : DataPacket(64) {
	entityID = 0;
	entityType = 0;
	pitch = 0;
	yaw = 0;
}

void AddEntity::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::AddEntity));
	putVarULong(entityID);
	putVarULong(entityID); // RuntimeEntityID
	putVarUInt(entityType);
	Vector3f::serialize(entityPosition, *this);
	Vector3f::serialize(entityMotion, *this);
	putFloat(pitch);
	putFloat(yaw);
	putVarUInt(0); // EntityAttributes count
	putVarUInt(0); // EntityMetadata count
	putVarUInt(0); // EntityLink count
}