#pragma once

#include <packets/DataPacket.h>

class MobEquipment : public RakLib::DataPacket {
public:
	uint64 entityID;
	// ItemStack item
	uint8 inventorySlot;
	uint8 hotbarSlot;
	uint8 unknown;

public:
	MobEquipment();

	void decode() override;

	void encode() override;
};