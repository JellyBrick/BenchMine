#pragma once

#include <packets/DataPacket.h>

class Animate : public RakLib::DataPacket {
public:
	uint32 action;
	uint64 entityID;

public:
	Animate();

	void encode() override;
};