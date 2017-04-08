#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3i.h"

class RemoveBlock : public RakLib::DataPacket {
public:
	Vector3i blockPosition;

public:
	RemoveBlock();

	void decode() override;
};
