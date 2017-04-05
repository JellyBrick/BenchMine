#pragma once

#include <packets/DataPacket.h>

class ResourceChunkRequest : public RakLib::DataPacket {
public:
	std::string packID;
	int32 chunkIndex;

public:
	ResourceChunkRequest();

	void decode() override;

	void encode() override;
};