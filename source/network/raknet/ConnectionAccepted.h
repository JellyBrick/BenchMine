#pragma once

#include <cstdlib>

#include <RakLib/protocol/DataPacket.h>

class ConnectionAccepted : public RakLib::DataPacket
{
public:
	int64 sendPing;
	int64 sendPong;

public:
	ConnectionAccepted(const std::string& clientIP, uint16 clientPort, int64 sendPing, int64 sendPong);

	void encode() override;
	void putAddress(const std::string& address, uint16 port);
};