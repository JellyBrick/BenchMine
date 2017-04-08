#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3f.h"

class MoveEntity : public RakLib::DataPacket {
public:
	uint64 entityID;
	Vector3f entityPosition;
	f32 pitch;
	f32 yaw;
	f32 headYaw;

public:
	MoveEntity();

	void decode() override;

	void encode() override;
};
