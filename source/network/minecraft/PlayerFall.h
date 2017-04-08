#pragma once

#include <RakLib/protocol/DataPacket.h>

class PlayerFall : public RakLib::DataPacket {
public:
	f32 fallDistance;

public:
	PlayerFall();

	void decode() override;
};