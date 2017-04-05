#include "AddPainting.h"

#include "MinecraftPackets.h"

// TODO: Remove placeholder packet size
AddPainting::AddPainting() : DataPacket(128){
	this->entityId = 0;
	this->direction = 0x00;
}

void AddPainting::encode() {
	this->putByte((uint8)MinecraftPackets::AddPainting);
	this->putVarULong(this->entityId);
	this->putVarULong(this->entityId); // RuntimeEntityID
	Vector3i::serialize(this->blockPosition, *this);
	this->putByte(this->direction);
	this->putString(this->title);
}