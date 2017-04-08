#pragma once

#include <RakLib/protocol/DataPacket.h>

class UpdateTrade : public RakLib::DataPacket {
public:

public:
	UpdateTrade();

	void decode() override;

	void encode() override;
};