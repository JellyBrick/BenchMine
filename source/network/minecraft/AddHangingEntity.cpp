#include "AddHangingEntity.h"

#include "MinecraftPackets.h"

//TODO: Remove placeholder packet size
AddHangingEntity::AddHangingEntity() : DataPacket(512) {
	this->entityID = 0;
	this->unknown = 0;
}

void AddHangingEntity::encode() {
	this->putByte((uint8)MinecraftPackets::AddHangingEntity);
	this->putULong(this->entityID);
	this->putULong(this->entityID); // RuntimeEntityID
	Vector3i::serialize(this->entityPosition, *this);
	this->putVarUInt(this->unknown);
}