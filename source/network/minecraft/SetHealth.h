#pragma once

#include <packets/DataPacket.h>

class SetHealth : public RakLib::DataPacket {
public:
	uint32 health;

public:
	SetHealth();

	void encode() override;
};