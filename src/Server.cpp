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
	this->_raklib = new RakLib::RakLib("", 19132, this);
	this->_maxPlayers = 10;
	this->_ip = "0.0.0.0";
	this->_port = 19132;
	this->_motd = "Welcome to the BenchMine Server!";
	this->_title = "BenchMine Minecraft Server!";
}

void Server::start()
{
	std::cout << "Starting RakLib..." << std::endl;
	this->_raklib->start();
}

void Server::stop()
{
	std::cout << "Stopping RakLib" << std::endl;
	this->_raklib->stop();
}

bool Server::addSession(std::string ip, unsigned short port, long clientID, unsigned short mtu)
{
	std::cout << "Adding Session" << std::endl;
	return false;
}

bool Server::removeSession(std::string ip, unsigned short port)
{
	return false;
}

RakLib::Session* Server::getSession(std::string ip, unsigned short port)
{
	return nullptr;
}

Server::~Server()
{
    this->stop();
}
