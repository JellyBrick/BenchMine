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
#include "Player.h"

Server::Server()
{
	this->_maxPlayers = 10;
	this->_ip = "0.0.0.0";
	this->_port = 19132;
	this->_motd = "Welcome to the BenchMine Server!";
	this->_title = "BenchMine Minecraft Server!";
	this->_raklib = new RakLib::RakLib(this, "", 19132);
	this->_logger = new ColoredLogger();


	this->_logger->info("BenchMine Server Software under LGPL v3");
}

void Server::start()
{
	this->_logger->info("Server at %s:%d - %s", this->_ip.c_str(), this->_port, this->_title.c_str());
	//TODO: Do more stuff between XD

	this->_raklib->start();
	this->_logger->info("Started RakLib...");
}

void Server::stop()
{
	this->_raklib->stop();
	this->_logger->info("Stopping RakLib");
}

bool Server::addSession(std::string ip, unsigned short port, long clientID, unsigned short mtu)
{
	if (this->_players.size() > this->_maxPlayers)
		return false;

	this->_logger->notice("New player have joined - %s:%d", ip.c_str(), port);

	this->_players[this->_raklib->getSessionIdentifier(ip, port)] = new Player(this, ip, port, clientID, mtu);
	return true;
}

bool Server::removeSession(std::string ip, unsigned short port)
{
	if (this->_players[this->_raklib->getSessionIdentifier(ip, port)] == nullptr)
		return false;

	//The session should delete his resource
	delete this->_players[this->_raklib->getSessionIdentifier(ip, port)];
	return true;
}

RakLib::Session* Server::getSession(std::string ip, unsigned short port)
{
	return this->_players[this->_raklib->getSessionIdentifier(ip, port)];
}

Server::~Server()
{
    this->stop();
}
