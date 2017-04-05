#include "ResourcePackChunkRequest.h"

#include "MinecraftPackets.h"

ResourceChunkRequest::ResourceChunkRequest() : DataPacket(128) {
	this->chunkIndex = 0;
}

void ResourceChunkRequest::decode() {
	++this->position; // Skip Packet ID
	this->packID = this->getVarString();
	this->chunkIndex = this->getInt();
}

void ResourceChunkRequest::encode() {
	this->putByte((uint8)MinecraftPackets::ResourcePackChunkRequest);
	this->putVarString(this->packID);
	this->putInt(this->chunkIndex);
}