#pragma once

#include <packets/DataPacket.h>

#include "world/math/Vector3i.h"

class AddHangingEntity : public RakLib::DataPacket {
public:
	uint64 entityID;
	Vector3i entityPosition;
	uint32 unknown;

public:
	AddHangingEntity();

	void encode() override;
};