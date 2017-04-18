#pragma once

#include <RakLib/protocol/DataPacket.h>

class ChunkRadiusUpdated : public RakLib::DataPacket {
public:
	int32 viewRadius;

public:
	ChunkRadiusUpdated(int32 radius);

	void encode() override;
};