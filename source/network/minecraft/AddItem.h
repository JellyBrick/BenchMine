#pragma once

#include <packets/DataPacket.h>

class AddItem : public RakLib::DataPacket {
public:
	//ItemStack

public:
	AddItem();

	void encode() override;
};