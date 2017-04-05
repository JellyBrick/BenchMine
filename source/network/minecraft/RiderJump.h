#pragma once

#include <packets/DataPacket.h>

class RiderJump : public RakLib::DataPacket {
public:
	uint32 unknown;

public:
	RiderJump();

	void decode() override;

	void encode() override;
};