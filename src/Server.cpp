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

#include "Server.h"

Server::Server()
{
	this->playerManager = new PlayerManager(10);
	this->maxPlayers = 10;
	this->port = 19132;
}

void Server::Start()
{
	std::cout << "Server Started..." << std::endl;
	this->playerManager->Start();
}

std::string Server::getIP()
{
	return std::string("0.0.0.0");
}

int Server::getPort()
{
	return 19132;
}

PlayerManager* Server::getPlayerManager()
{
	return this->playerManager;
}

std::string Server::getTitle()
{
	return "Minecraft Server!";//return this->title;
}

void Server::Stop()
{
	this->playerManager->Stop();
}

Server::~Server()
{
    this->Stop();
}
