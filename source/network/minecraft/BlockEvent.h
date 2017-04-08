#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3i.h"

class BlockEvent : public RakLib::DataPacket {
public:
	Vector3i blockPosition;
	uint32 case1;
	uint32 case2;

public:
	BlockEvent();

	void encode() override;
};