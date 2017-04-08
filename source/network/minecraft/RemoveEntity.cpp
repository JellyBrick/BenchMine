#include "RemoveEntity.h"

#include "MinecraftPackets.h"

RemoveEntity::RemoveEntity() : DataPacket(16) {
	entityID = 0;
}

void RemoveEntity::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::RemoveEntity));
	putVarULong(entityID);
}