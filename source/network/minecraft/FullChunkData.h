#pragma once

#include <RakLib/protocol/DataPacket.h>

class FullChunkData : public RakLib::DataPacket {
public:
	int32 chunkX, chunkZ;
	uint32 payloadSize;
	uint8* payload;

public:
	FullChunkData(int32 x, int32 z, uint8* payload, uint32 payloadSize);
	~FullChunkData();

	void encode() override;
};