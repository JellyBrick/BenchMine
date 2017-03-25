#pragma once

#include <packets\DataPacket.h>

class ConnectionRequest : public RakLib::DataPacket
{
public:
	int64 clientID;
	uint64 sendPing;
	bool useSecurity;

public:
	ConnectionRequest(std::unique_ptr<Packet> packet);

	void decode() override;
};