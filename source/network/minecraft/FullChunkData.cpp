#include "FullChunkData.h"

#include "MinecraftPackets.h"

FullChunkData::FullChunkData(int32 x, int32 z, uint8* payload, uint32 payloadSize) : RakLib::DataPacket(14 + payloadSize) {
	this->chunkX = x;
	this->chunkZ = z;
	this->payloadSize = payloadSize;
	this->payload = payload;
}

FullChunkData::~FullChunkData() {
	// Here we should clean up chunk payload, but since we are using the same chunk among Packets we can't
	// delete[] payload;
}

void FullChunkData::encode() {
	this->putByte((uint8)MinecraftPackets::FullChunkData);
	this->putVarUInt((uint32)this->chunkX);
	this->putVarUInt((uint32)this->chunkZ);
	this->putVarUInt((uint32)this->payloadSize);
	this->putByte(this->payload, this->payloadSize);
}

