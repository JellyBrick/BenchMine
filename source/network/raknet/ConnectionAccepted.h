#pragma once

#include <packets\DataPacket.h>

class ConnectionAccepted : public RakLib::DataPacket
{
public:
	int64 sendPing;
	int64 sendPong;

public:
	ConnectionAccepted(const std::string& ip, uint16 port, int64 sendPing, int64 sendPong);

	void encode() override;
	void putAddress(const std::string& address, uint16 port);
};