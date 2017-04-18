#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3f.h"

class ChangeDimension : public RakLib::DataPacket {
public:
	enum Dimension {
		Overworld,
		Nether
	};

	Dimension dimension;
	Vector3f spawnPosition;
	bool unknown;

public:
	ChangeDimension();

	void encode() override;
};