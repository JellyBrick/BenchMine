#include "UpdateBlock.h"

#include "MinecraftPackets.h"

UpdateBlock::UpdateBlock() : DataPacket(32) {
	this->blockID = 0x00;
	this->blockData = 0x00;
	this->flags = FLAG_ALL;
}

void UpdateBlock::encode() {
	this->putByte((uint8)MinecraftPackets::UpdateBlock);
	Vector3i::serialize(this->blockPosition, *this);
	this->putByte(this->blockID);
	this->putByte((this->flags << 4) | this->blockData);
}