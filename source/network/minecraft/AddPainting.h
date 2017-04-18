#pragma once

#include <string>

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3i.h"

class AddPainting : public RakLib::DataPacket {
public:
	uint64 entityId;
	Vector3i blockPosition;
	uint8 direction;
	std::string title;

public:
	AddPainting();

	void encode() override;
};