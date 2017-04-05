#include "BlockPickRequest.h"

#include "MinecraftPackets.h"

BlockPickRequest::BlockPickRequest() : DataPacket(16) {
	this->hotbarSlot = 0x00;
}

void BlockPickRequest::decode() {
	++this->position; // Skip Packet ID
	this->blockPosition = Vector3i::deserialize(*this);
	this->hotbarSlot = this->getByte();
}

void BlockPickRequest::encode() {
	this->putByte((uint8)MinecraftPackets::BlockPickRequest);
	Vector3i::serialize(this->blockPosition, *this);
	this->putByte(this->hotbarSlot);
}