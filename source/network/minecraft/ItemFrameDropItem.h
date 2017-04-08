#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3i.h"

class ItemFrameDropItem : public RakLib::DataPacket {
public:
	Vector3i blockPosition;

public:
	ItemFrameDropItem();

	void decode() override;
};
