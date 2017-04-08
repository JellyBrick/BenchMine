#pragma once

#include <RakLib/protocol/DataPacket.h>

class AvailableCommands : public RakLib::DataPacket {
public:
	std::string commands;
	std::string unknown;

public:
	AvailableCommands();

	void encode() override;
};