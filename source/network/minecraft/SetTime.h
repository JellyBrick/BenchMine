#pragma once

#include <RakLib/protocol/DataPacket.h>

class SetTime : public RakLib::DataPacket {
public:
	int32 levelTime;
	bool haveStarted;

public:
	SetTime(int32 time, bool started);

	void encode() override;
};