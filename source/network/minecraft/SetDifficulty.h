#pragma once

#include <packets/DataPacket.h>

class SetDifficulty : public RakLib::DataPacket {
public:
	uint32 difficulty;

public:
	SetDifficulty();

	void encode() override;
};