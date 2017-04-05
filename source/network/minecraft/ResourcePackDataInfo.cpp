#include "ResourcePackDataInfo.h"

#include "MinecraftPackets.h"

ResourcePackDataInfo::ResourcePackDataInfo() : DataPacket(512) {
	this->maxChunkSize = 0;
	this->chunkCount = 0;
	this->compressedPackSize = 0;
}

void ResourcePackDataInfo::decode() {
	++this->position; // Skip Packet ID
	this->packID = this->getVarString();
	this->maxChunkSize = this->getUInt();
	this->chunkCount = this->getUInt();
	this->compressedPackSize = this->getUInt();
	this->sha256 = this->getVarString();
}

void ResourcePackDataInfo::encode() {
	this->putByte((uint8)MinecraftPackets::ResourcePackDataInfo);
	this->putVarString(this->packID);
	this->putInt(this->maxChunkSize);
	this->putInt(this->chunkCount);
	this->putInt(this->compressedPackSize);
	this->putVarString(this->sha256);
}