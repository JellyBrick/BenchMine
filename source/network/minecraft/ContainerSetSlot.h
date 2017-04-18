#pragma once

#include <RakLib/protocol/DataPacket.h>

class ContainerSetSlot : public RakLib::DataPacket {
public:
	uint8 windowsID;
	uint32 slot;
	uint32 hotbarSlot;
	//ItemStack item
	uint8 selectedSlot;

public:
	ContainerSetSlot();

	void decode() override;

	void encode() override;
};