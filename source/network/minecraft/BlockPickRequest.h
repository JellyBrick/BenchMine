#pragma once

#include <packets/DataPacket.h>

#include "world/math/Vector3i.h"

class BlockPickRequest : public RakLib::DataPacket {
public:
	Vector3i blockPosition;
	uint8 hotbarSlot;

public:
	BlockPickRequest();

	void decode() override;

	void encode() override;
};