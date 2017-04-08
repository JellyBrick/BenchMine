#pragma once

#include <RakLib/protocol/DataPacket.h>

class SetTitle : public RakLib::DataPacket {
public:
	enum Action {
		CLEAR_TITLE = 0,
		RESET_TITLE = 1,
		SET_TITLE = 2,
		SET_SUBTITLE = 3,
		SET_ACTIONBAR_MESSAGE = 4,
		SET_ANIMATION_TIMES = 5
	};

	Action action;
	std::string text;
	uint32 fadeInTime;
	uint32 stayTime;
	uint32 fadeOutTime;

public:
	SetTitle();

	void decode() override;

	void encode() override;
};