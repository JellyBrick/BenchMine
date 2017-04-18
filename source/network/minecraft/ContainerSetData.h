#pragma once

#include <RakLib/protocol/DataPacket.h>

class ContainerSetData : public RakLib::DataPacket {
public:
	uint8 windowID;
	uint32 property;
	uint32 value;

public:
	ContainerSetData();

	void encode() override;
};