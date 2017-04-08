#pragma once

#include <RakLib/protocol/DataPacket.h>

class ReplaceSelectedSlot : public RakLib::DataPacket {
public:
	// ItemStack item

public:
	ReplaceSelectedSlot();

	void encode() override;
};