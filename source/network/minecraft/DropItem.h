#pragma once

#include <packets/DataPacket.h>

class DropItem : public RakLib::DataPacket {
public:
	uint8 type;
	// ItemStack item

public:
	DropItem();

	void decode() override;
};