#pragma once

#include <packets/DataPacket.h>

class MobArmorEquipment : public RakLib::DataPacket {
public:
	uint64 entityID;
	// std::array<ItemStack, 4> amorSlots;

public:
	MobArmorEquipment();

	void decode() override;

	void encode() override;
};