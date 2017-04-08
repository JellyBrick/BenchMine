#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3f.h"

class Respawn : public RakLib::DataPacket {
public:
	Vector3f spawnPosition;

public:
	Respawn();

	void decode() override;

	void encode() override;
};
