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

#include "Entity/Entity.h"

class Server;
class Player : public Entity, public RakLib::Session
{
private:
	std::string _username;

	int _CID;

	Server* _server;

public:
	Player(Server* server, std::string ip, uint16 port, long clientID, short mtuSize);
	~Player();

	void close(std::string reason);

	void handleDataPacket(const RakLib::DataPacket& packet);
	void sendPacket(RakLib::Packet* packet);

	inline const std::string& getUsername() const { this->_username; };
	const std::string getLUsername();

};
#endif