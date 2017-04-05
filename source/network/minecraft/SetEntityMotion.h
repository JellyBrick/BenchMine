#pragma once

#include <packets/DataPacket.h>

#include "world/math/Vector3f.h"

class SetEntityMotion : public RakLib::DataPacket {
public:
	uint64 entityID;
	Vector3f entityMotion;

public:
	SetEntityMotion();

	void encode() override;
};
