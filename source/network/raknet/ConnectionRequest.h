#pragma once

#include <RakLib/protocol/DataPacket.h>

class ConnectionRequest : public RakLib::DataPacket
{
public:
	int64 clientID;
	uint64 sendPing;
	bool useSecurity;

public:
	ConnectionRequest(std::unique_ptr<RakLib::Packet>&& packet);

	void decode() override;
};