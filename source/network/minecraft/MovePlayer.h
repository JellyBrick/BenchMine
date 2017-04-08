#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3f.h"

class MovePlayer : public RakLib::DataPacket {
public:
	enum Mode {
		NORMAL,
		RESET,
		ROTATE

	};

	uint64 entityID;
	Vector3f entityPosition;
	f32 pitch;
	f32 yaw;
	f32 bodyYaw;
	Mode mode;
	bool onGround;

public:
	MovePlayer();

	void decode() override;

	void encode() override;
};
