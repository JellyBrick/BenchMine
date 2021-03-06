#pragma once

#include <RakLib/protocol/DataPacket.h>

class SetEntityLink : public RakLib::DataPacket {
public:
	uint64 from;
	uint64 to;
	uint8 type;

public:
	SetEntityLink();

	void encode() override;
};