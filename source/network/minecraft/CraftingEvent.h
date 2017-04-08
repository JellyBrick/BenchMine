#pragma once

#include <RakLib/protocol/DataPacket.h>

class CraftingEvent : public RakLib::DataPacket {
public:
	uint8 windowID;
	uint32 type;
	std::string UUID;
	//std::vector<ItemStack> input
	//std::vector<ItemStack> output

public:
	CraftingEvent();

	void decode() override;
};