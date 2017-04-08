#pragma once

#include <RakLib/protocol/DataPacket.h>

class InventoryAction : public RakLib::DataPacket {
public:
	uint32 unknown;
	// ItemStack item

public:
	InventoryAction();

	void encode() override;
};