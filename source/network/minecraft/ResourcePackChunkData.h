#pragma once

#include <packets/DataPacket.h>

class ResourcePackChunkData : public RakLib::DataPacket {
public:
	std::string packID;
	int32 chunkIndex;
	int64 progress;
	uint32 chunkDataSize;
	uint8* chunkData;

public:
	ResourcePackChunkData();

	void decode() override;

	void encode() override;
};