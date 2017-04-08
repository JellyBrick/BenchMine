#include "AddHangingEntity.h"

#include "MinecraftPackets.h"

//TODO: Remove placeholder packet size
AddHangingEntity::AddHangingEntity() : DataPacket(512) {
	entityID = 0;
	unknown = 0;
}

void AddHangingEntity::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::AddHangingEntity));
	putULong(entityID);
	putULong(entityID); // RuntimeEntityID
	Vector3i::serialize(entityPosition, *this);
	putVarUInt(unknown);
}