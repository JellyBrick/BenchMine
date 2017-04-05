#pragma once

#include <packets/DataPacket.h>

class CraftingData : public RakLib::DataPacket {
public:
	//std::vector<Recipe> recipes

public:
	CraftingData();

	void decode() override;

	void encode() override;
};