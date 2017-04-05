#pragma once

#include <packets/DataPacket.h>

class SetCommandsEnabled : public RakLib::DataPacket {
public:
	bool enabled;

public:
	SetCommandsEnabled();

	void encode() override;
};