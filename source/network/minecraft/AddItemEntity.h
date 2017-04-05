#pragma once

#include <packets/DataPacket.h>

#include "world/math/Vector3f.h"

class AddItemEntity : public RakLib::DataPacket {
public:
	uint64 entityId;
	// ItemStack item
	Vector3f entityPosition;
	Vector3f entityMotion;

public:
	AddItemEntity();

	void encode() override;
};