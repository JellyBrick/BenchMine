#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3i.h"

class ContainerOpen : public RakLib::DataPacket {
public:
	uint8 windowsID;
	uint8 type;
	uint32 slots;
	Vector3i containerPosition;
	uint32 entityID;

public:
	ContainerOpen();

	void encode() override;
};