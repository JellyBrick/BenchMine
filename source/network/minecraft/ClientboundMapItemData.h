#pragma once

#include <packets/DataPacket.h>

class ClientboundMapItemData : public RakLib::DataPacket {
public:

public:
	ClientboundMapItemData();

	void decode() override;

	void encode() override;
};