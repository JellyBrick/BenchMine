#pragma once

#include <RakLib/protocol/DataPacket.h>

class EntityEvent : public RakLib::DataPacket {
public:
	uint64 entityID;
	uint8 event;
	uint32 unknown;

public:
	EntityEvent();

	void decode() override;

	void encode() override;
};