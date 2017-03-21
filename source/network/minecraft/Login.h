#pragma once

#include <packets\DataPacket.h>

class Login : public RakLib::DataPacket
{
public:
	std::string username;
	int protocol;
	int protocol2;
	int clientID;
	std::string loginData;

public:
	Login(std::unique_ptr<Packet> packet);
	void decode() override;
};
