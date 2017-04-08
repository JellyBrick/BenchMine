#pragma once

#include <RakLib/protocol/DataPacket.h>

class AddItem : public RakLib::DataPacket {
public:
	//ItemStack

public:
	AddItem();

	void encode() override;
};