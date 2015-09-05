/**
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* @author InusualZ
*
*
*/
#ifndef LOGIN_H
#define LOGIN_H

#include <RakLib\Packets\DataPacket.h>

class Login : public RakLib::DataPacket
{
public:
	std::string username;
	int protocol;
	int protocol2;
	int clientID;
	std::string loginData;

public:
	Login(Packet* packet);
	void decode() override;
};

#endif