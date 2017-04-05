#pragma once

#include <packets/DataPacket.h>

class PlayerFall : public RakLib::DataPacket {
public:
	f32 fallDistance;

public:
	PlayerFall();

	void decode() override;
};