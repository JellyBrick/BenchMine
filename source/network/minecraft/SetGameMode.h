#pragma once

#include <packets/DataPacket.h>

class SetGameMode : public RakLib::DataPacket {
public:
	uint32 gamemode;

public:
	SetGameMode();

	void encode() override;
};