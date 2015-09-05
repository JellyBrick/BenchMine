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

Player::Player(std::string ip, uint16_t port, long clientID, short mtuSize) : RakLib::Session(ip, port, clientID, mtuSize)
{
	this->username = "Steve";

	//this->server.getScheduler().addTask(new CallbackTask(this, "update", 10, true));
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
	this->server->sendPacket(packet);
}
