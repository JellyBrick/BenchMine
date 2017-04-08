#pragma once

#include <RakLib/protocol/DataPacket.h>

class Interact : public RakLib::DataPacket {
public:
	enum Action {
		NONE = 0,
		RIGHT_CLICK = 1,
		LEFT_CLICK = 2,
		LEAVE_VEHICLE = 3,
		MOUSE_HOOVER = 5
	};

	Action action;
	uint64 entityID;

public:
	Interact();

	void decode() override;

	void encode() override;
};