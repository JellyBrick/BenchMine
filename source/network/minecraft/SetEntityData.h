#pragma once

#include <packets/DataPacket.h>

class SetEntityData : public RakLib::DataPacket {
public:
	uint64 entityID;
	// EntityMetata entityMetadata;

public:
	SetEntityData();

	void encode() override;
};