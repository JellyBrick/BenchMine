#pragma once

#include <RakLib/protocol/DataPacket.h>

class DropItem : public RakLib::DataPacket {
public:
	uint8 type;
	// ItemStack item

public:
	DropItem();

	void decode() override;
};