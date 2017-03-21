#pragma once

#include <packets\DataPacket.h>

class ClientConnect : public RakLib::DataPacket
{
public:
	int64 clientID;
	int64 sendPing;
	bool useSecurity;

public:
	ClientConnect(std::unique_ptr<Packet> packet);

	void decode() override;
};