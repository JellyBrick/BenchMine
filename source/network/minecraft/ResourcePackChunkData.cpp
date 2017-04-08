#include "ResourcePackChunkData.h"

#include "MinecraftPackets.h"

ResourcePackChunkData::ResourcePackChunkData() : DataPacket(DEFAULT_BUFFER_SIZE) {
	chunkIndex = 0;
	progress = 0;
	chunkDataSize = 0;
	chunkData = nullptr;
}

void ResourcePackChunkData::decode() {
	++position; // Skip Packet ID
	packID = getVarString();
	chunkIndex = getInt();
	progress = getLong();
	chunkDataSize = getInt();
	chunkData = getByte(chunkDataSize);
}

void ResourcePackChunkData::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ResourcePackChunkData));
	putVarString(packID);
	putInt(chunkIndex);
	putLong(progress);
	putInt(chunkDataSize);
	putByte(chunkData, chunkDataSize);
}