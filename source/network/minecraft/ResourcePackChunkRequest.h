#pragma once

#include <packets/DataPacket.h>

class ResourcePackChunkRequest : public RakLib::DataPacket {
public:
	std::string packID;
	int32 chunkIndex;

public:
	ResourcePackChunkRequest();

	void decode() override;

	void encode() override;
};