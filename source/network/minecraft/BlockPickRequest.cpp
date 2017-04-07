#include "BlockPickRequest.h"

#include "MinecraftPackets.h"

BlockPickRequest::BlockPickRequest() : DataPacket(16) {
	hotbarSlot = 0x00;
}

void BlockPickRequest::decode() {
	++position; // Skip Packet ID
	blockPosition = Vector3i::deserialize(*this);
	hotbarSlot = getByte();
}

void BlockPickRequest::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::BlockPickRequest));
	Vector3i::serialize(blockPosition, *this);
	putByte(hotbarSlot);
}