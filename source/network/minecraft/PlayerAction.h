#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3f.h"

class PlayerAction : public RakLib::DataPacket {
public:
	enum Action {
		START_BREAK = 0,
		ABORT_BREAK = 1,
		STOP_BREAK = 2,

		RELEASE_ITEM = 5,
		STOP_SLEEPING = 6,
		RESPAWN = 7,
		JUMP = 8,

		START_SPRINT = 9,
		STOP_SPRINT = 10,

		START_SNEAK = 11,
		STOP_SNEAK = 12,

		START_GLIDE = 15,
		STOP_GLIDE = 16,
	};

	uint64 entityID;
	Action action;
	Vector3f entityPosition;
	uint32 face;

public:
	PlayerAction();

	void decode() override;

	void encode() override;
};
