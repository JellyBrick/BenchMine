#include "ChunkRadiusUpdated.h"

#include "MinecraftPackets.h"

ChunkRadiusUpdated::ChunkRadiusUpdated(int32 radius) : DataPacket(5) {
	viewRadius = radius;
}

void ChunkRadiusUpdated::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ChunkRadiusUpdate));
	putVarUInt(static_cast<uint32>(viewRadius));
}