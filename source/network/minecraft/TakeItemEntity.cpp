#include "TakeItemEntity.h"

#include "MinecraftPackets.h"

TakeItemEntity::TakeItemEntity() : DataPacket(24) {
	this->target = 0;
	this->entityID = 0;
}

void TakeItemEntity::decode() {
	++this->position; // Skip Packet ID;
	this->target = this->getVarULong();
	this->entityID = this->getVarULong();
}

void TakeItemEntity::encode() {
	this->putByte((uint8)MinecraftPackets::TakeItemEntity);
	this->putVarULong(this->target);
	this->putVarULong(this->entityID);
}