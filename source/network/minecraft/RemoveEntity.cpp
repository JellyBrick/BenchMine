#include "RemoveEntity.h"

#include "MinecraftPackets.h"

RemoveEntity::RemoveEntity() : DataPacket(16) {
	this->entityID = 0;
}

void RemoveEntity::encode() {
	this->putByte((uint8)MinecraftPackets::RemoveEntity);
	this->putVarULong(this->entityID);
}
