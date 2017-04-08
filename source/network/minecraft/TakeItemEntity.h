#pragma once

#include <RakLib/protocol/DataPacket.h>

class TakeItemEntity : public RakLib::DataPacket {
public:
	uint64 target;
	uint64 entityID;

public:
	TakeItemEntity();

	void decode() override;

	void encode() override;
};