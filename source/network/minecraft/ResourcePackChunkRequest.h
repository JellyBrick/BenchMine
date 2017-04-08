#pragma once

#include <RakLib/protocol/DataPacket.h>

class ResourcePackChunkRequest : public RakLib::DataPacket {
public:
	std::string packID;
	int32 chunkIndex;

public:
	ResourcePackChunkRequest();

	void decode() override;

	void encode() override;
};