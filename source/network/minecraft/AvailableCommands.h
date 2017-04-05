#pragma once

#include <packets/DataPacket.h>

class AvailableCommands : public RakLib::DataPacket {
public:
	std::string commands;
	std::string unknown;

public:
	AvailableCommands();

	void encode() override;
};