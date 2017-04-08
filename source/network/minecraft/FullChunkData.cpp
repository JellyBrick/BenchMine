#include "FullChunkData.h"

#include "MinecraftPackets.h"

FullChunkData::FullChunkData(int32 x, int32 z, uint8* payload, uint32 payloadSize) 
	: RakLib::DataPacket(14 + payloadSize), chunkX(x), chunkZ(z), payloadSize(payloadSize), payload(payload) {}

FullChunkData::~FullChunkData() {
	// Here we should clean up chunk payload, but since we are using the same chunk among Packets we can't
	// delete[] payload;
}

void FullChunkData::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::FullChunkData));
	putVarUInt(static_cast<uint32>(chunkX));
	putVarUInt(static_cast<uint32>(chunkZ));
	putVarUInt(static_cast<uint32>(payloadSize));
	putByte(payload, payloadSize);
}