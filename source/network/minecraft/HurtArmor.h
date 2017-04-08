#pragma once

#include <RakLib/protocol/DataPacket.h>

class HurtArmor : public RakLib::DataPacket {
public:
	uint32 health;

public:
	HurtArmor();

	void encode() override;
};