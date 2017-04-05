#pragma once

#include <packets/DataPacket.h>

#include "world/math/Vector3i.h"

class PlaySound : public RakLib::DataPacket {
public:
	std::string soundID;
	Vector3i eventPosition;
	f32 unknown1;
	f32 unknown2;

public:
	PlaySound();

	void decode() override;

	void encode() override;
};
