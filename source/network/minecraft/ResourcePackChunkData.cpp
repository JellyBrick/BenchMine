#include "ResourcePackChunkData.h"

#include "MinecraftPackets.h"

ResourcePackChunkData::ResourcePackChunkData() : DataPacket(DEFAULT_BUFFER_SIZE) {
	this->chunkIndex = 0;
	this->progress = 0;
	this->chunkDataSize = 0;
	this->chunkData = nullptr;
}

void ResourcePackChunkData::decode() {
	++this->position; // Skip Packet ID
	this->packID = this->getVarString();
	this->chunkIndex = this->getInt();
	this->progress = this->getLong();
	this->chunkDataSize = this->getInt();
	this->chunkData = this->getByte(this->chunkDataSize);
}

void ResourcePackChunkData::encode() {
	this->putByte((uint8)MinecraftPackets::ResourcePackChunkData);
	this->putVarString(this->packID);
	this->putInt(this->chunkIndex);
	this->putLong(this->progress);
	this->putInt(this->chunkDataSize);
	this->putByte(this->chunkData, this->chunkDataSize);
}