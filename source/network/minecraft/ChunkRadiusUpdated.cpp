#include "ChunkRadiusUpdated.h"

#include "MinecraftPackets.h"

ChunkRadiusUpdated::ChunkRadiusUpdated(int32 radius) : DataPacket(5) {
	viewRadius = radius;
}

void ChunkRadiusUpdated::encode() {
	this->putByte((uint8)MinecraftPackets::ChunkRadiusUpdate);
	this->putVarUInt((uint32)this->viewRadius);
}