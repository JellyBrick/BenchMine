#pragma once

#include <RakLib/protocol/DataPacket.h>

class ContainerClose : public RakLib::DataPacket {
public:
	uint8 windowID;

public:
	ContainerClose();

	void decode() override;

	void encode() override;
};