#include "AddItemEntity.h"

#include "MinecraftPackets.h"

AddItemEntity::AddItemEntity() : DataPacket(128) {
	entityId = 0;
}

void AddItemEntity::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::AddItemEntity));
	// TODO: When we have an proper inventory system
}