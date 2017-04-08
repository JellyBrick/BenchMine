#include "TakeItemEntity.h"

#include "MinecraftPackets.h"

TakeItemEntity::TakeItemEntity() : DataPacket(24) {
	target = 0;
	entityID = 0;
}

void TakeItemEntity::decode() {
	++position; // Skip Packet ID;
	target = getVarULong();
	entityID = getVarULong();
}

void TakeItemEntity::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::TakeItemEntity));
	putVarULong(target);
	putVarULong(entityID);
}