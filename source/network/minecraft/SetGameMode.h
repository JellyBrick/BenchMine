#pragma once

#include <RakLib/protocol/DataPacket.h>

class SetGameMode : public RakLib::DataPacket {
public:
	uint32 gamemode;

public:
	SetGameMode();

	void encode() override;
};