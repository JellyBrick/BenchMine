#pragma once

#include <RakLib/protocol/DataPacket.h>

class ResourcePackDataInfo : public RakLib::DataPacket {
public:
	std::string packID;
	uint32 maxChunkSize;
	uint32 chunkCount;
	uint32 compressedPackSize;
	std::string sha256;

public:
	ResourcePackDataInfo();

	void decode() override;

	void encode() override;
};