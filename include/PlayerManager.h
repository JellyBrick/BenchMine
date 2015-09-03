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
#ifndef PLAYER_MANAGER_H_
#define PLAYER_MANAGER_H_

#include <map>

#include "Player.h"
#include "Server.h"
#include "Network/SocketHandler.h"
#include "Network/Packet.h"

class Server;
class SocketHandler;
class Player;
class PlayerManager
{
private:
	int maxPlayers;
	SocketHandler* socketHandler;
	std::map<std::string, Player*> players;

public:
	PlayerManager(int maxPlayers);
	~PlayerManager();

	Player* getPlayer(std::string identifier);
	std::string getPlayerIdentifier(std::string ip, uint16_t port);

	void Start();
	void Stop();

	void sendPacket(Packet* packet);

	void handlePacket(Packet*);
};
#endif
