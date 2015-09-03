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

#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <atomic>
#include <mutex>
#include <memory>

#include "PlayerManager.h"

class PlayerManager;
class Player;
class Server
{
public:
	static std::atomic<Server*> m_instance;
	static std::mutex m_mutex;
	static Server* getInstance();

private:
	int port;
	int maxPlayers;
	std::string  ip;
	std::string motd;
	std::string title;
	PlayerManager* playerManager;

public:
	Server();
	~Server();

	void Start();

	int getPort(); // Server Ports
	int getMaxPlayers(); // Server Max Players
	std::string getIP(); // Server IP
	std::string getMOTD(); // Message of the day.
	std::string getTitle(); // Server Title
	PlayerManager* getPlayerManager();

	void Stop();
};
#endif
