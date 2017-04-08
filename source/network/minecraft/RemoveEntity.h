#pragma once

#include <RakLib/protocol/DataPacket.h>

class RemoveEntity : public RakLib::DataPacket {
public:
	uint64 entityID;

public:
	RemoveEntity();

	void encode() override;
};