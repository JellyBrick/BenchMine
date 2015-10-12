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

#include "Player.h"
#include "Server.h"

Player::Player(Server* server, std::string ip, uint16 port, long clientID, short mtuSize) : RakLib::Session(ip, port, clientID, mtuSize)
{
	this->_server = server;
	this->_username = "Steve";

	//this->server.getScheduler().addTask(new CallbackTask(this, "update", 10, true));
}

Player::~Player()
{
	//No resource to release
}

void Player::close(std::string reason)
{
	//TODO
}

void Player::handleDataPacket(const RakLib::DataPacket& packet)
{
	//TODO
}

void Player::sendPacket(RakLib::Packet* packet)
{
	this->_server->sendPacket(packet);
}


const std::string Player::getLUsername()
{
	//We should do this every time? or store the result as a member?
	std::string lname = this->_username.c_str();
	std::transform(lname.begin(), lname.end(), lname.begin(), ::tolower);
	return lname;
};