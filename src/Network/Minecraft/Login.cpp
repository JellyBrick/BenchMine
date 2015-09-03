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


#include "Network/Minecraft/Login.h"
Login::Login(InternalPacket* pck) : DataPacket(pck)
{
	this->username = "";
	this->clientID = 0;
	this->loginData = "";
	this->protocol = 0;
	this->protocol2 = 0;
}

void Login::decode()
{
	if (this->getByte() != MinecraftPackets::LOGIN_PACKET){
		throw std::runtime_error("Expected another packet.");
	}
	this->username = this->getString();
	this->protocol = this->getInt();
	this->protocol2 = this->getInt();
	this->clientID = this->getInt();
	this->loginData = this->getString();
}

void Login::encode()
{
	///Not Used
}