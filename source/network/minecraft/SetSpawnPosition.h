#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3i.h"

class SetSpawnPosition : public RakLib::DataPacket {
public:
	uint32 unknown1;
	Vector3i spawnPosition;
	bool unknown2;

public:
	SetSpawnPosition();

	void encode() override;
};
