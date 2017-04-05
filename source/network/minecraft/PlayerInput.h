#pragma once

#include <packets/DataPacket.h>

class PlayerInput : public RakLib::DataPacket {
public:
	f32 motionX;
	f32 motionY;
	bool unknown1;
	bool unknown2;

public:
	PlayerInput();

	void decode() override;
};