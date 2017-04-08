#pragma once

#include <RakLib/protocol/DataPacket.h>

class SetEntityData : public RakLib::DataPacket {
public:
	uint64 entityID;
	// EntityMetata entityMetadata;

public:
	SetEntityData();

	void encode() override;
};