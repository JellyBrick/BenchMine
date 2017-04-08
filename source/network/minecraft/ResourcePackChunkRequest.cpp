#include "ResourcePackChunkRequest.h"

#include "MinecraftPackets.h"

ResourcePackChunkRequest::ResourcePackChunkRequest() : DataPacket(128) {
	chunkIndex = 0;
}

void ResourcePackChunkRequest::decode() {
	++position; // Skip Packet ID
	packID = getVarString();
	chunkIndex = getInt();
}

void ResourcePackChunkRequest::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ResourcePackChunkRequest));
	putVarString(packID);
	putInt(chunkIndex);
}