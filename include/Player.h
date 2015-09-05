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

#ifndef PLAYER_H_
#define PLAYER_H_

#include <RakLib\Session.h>

#include "Server.h"
#include "Entity/Entity.h"

class Server;
class Player : public Entity, public RakLib::Session
{
private:
	std::string username;

	int CID;

	Server* server;

public:
	Player(std::string ip, uint16_t port, long clientID, short mtuSize);
	~Player();

	void close(std::string reason);

	void handleDataPacket(const RakLib::DataPacket& packet);
	void sendPacket(RakLib::Packet* packet);

	inline const std::string& getUsername() { this->username; };
	inline const std::string getLUsername() 
	{
		std::string lname = this->username.c_str();
		std::transform(lname.begin(), lname.end(), lname.begin(), ::tolower);
		return lname;
	};

};
#endif