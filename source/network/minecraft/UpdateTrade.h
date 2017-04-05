#pragma once

#include <packets/DataPacket.h>

class UpdateTrade : public RakLib::DataPacket {
public:

public:
	UpdateTrade();

	void decode() override;

	void encode() override;
};