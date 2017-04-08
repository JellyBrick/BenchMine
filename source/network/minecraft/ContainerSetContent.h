#pragma once

#include <RakLib/protocol/DataPacket.h>

class ContainerSetContent : public RakLib::DataPacket {
public:
	uint8 windowID;
	// std::vector<ItemStack> slots
	// std::vector<ItemStack> hotbar

public:
	ContainerSetContent();

	void decode() override;

	void encode() override;
};