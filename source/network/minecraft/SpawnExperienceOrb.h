#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3f.h"

class SpawnExperienceOrb : public RakLib::DataPacket {
public:
	Vector3f spawnPosition;
	uint32 amount;

public:
	SpawnExperienceOrb();

	void encode() override;
};