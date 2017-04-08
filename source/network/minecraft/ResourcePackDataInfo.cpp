#include "ResourcePackDataInfo.h"

#include "MinecraftPackets.h"

ResourcePackDataInfo::ResourcePackDataInfo() : DataPacket(512) {
	maxChunkSize = 0;
	chunkCount = 0;
	compressedPackSize = 0;
}

void ResourcePackDataInfo::decode() {
	++position; // Skip Packet ID
	packID = getVarString();
	maxChunkSize = getUInt();
	chunkCount = getUInt();
	compressedPackSize = getUInt();
	sha256 = getVarString();
}

void ResourcePackDataInfo::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ResourcePackDataInfo));
	putVarString(packID);
	putInt(maxChunkSize);
	putInt(chunkCount);
	putInt(compressedPackSize);
	putVarString(sha256);
}