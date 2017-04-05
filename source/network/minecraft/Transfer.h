#pragma once

#include <packets/DataPacket.h>

class Transfer : public RakLib::DataPacket {
public:
	std::string serverAddress;
	uint16 serverPort;

public:
	Transfer();

	void encode() override;
};