#include "AddEntity.h"

#include "MinecraftPackets.h"

// TODO: Remove placeholder size
AddEntity::AddEntity() : DataPacket(64) {
	this->entityID = 0;
	this->entityType = 0;
	this->pitch = 0;
	this->yaw = 0;
}

void AddEntity::encode() {
	this->putByte((uint8)MinecraftPackets::AddEntity);
	this->putVarULong(this->entityID);
	this->putVarULong(this->entityID); // RuntimeEntityID
	this->putVarUInt(this->entityType);
	Vector3f::serialize(this->entityPosition, *this);
	Vector3f::serialize(this->entityMotion, *this);
	this->putFloat(this->pitch);
	this->putFloat(this->yaw);
	this->putVarUInt(0); // EntityAttributes count
	this->putVarUInt(0); // EntityMetadata count
	this->putVarUInt(0); // EntityLink count
}