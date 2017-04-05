#pragma once

#include <string>

#include <packets/DataPacket.h>

class CommandStep : public RakLib::DataPacket {
public:
	std::string command;
	std::string overload;
	uint32 unknown1;
	uint32 unknown2;
	bool unknown3;
	uint64 unknown4;
	std::string args;
	std::string unknown5;

public:
	CommandStep();

	void decode() override;
};