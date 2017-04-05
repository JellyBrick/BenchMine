#include "AddItemEntity.h"

#include "MinecraftPackets.h"

AddItemEntity::AddItemEntity() : DataPacket(128) {
	this->entityId = 0;
}

void AddItemEntity::encode() {
	this->putByte((uint8)MinecraftPackets::AddItemEntity);
	// TODO: When we have an proper inventory system
}