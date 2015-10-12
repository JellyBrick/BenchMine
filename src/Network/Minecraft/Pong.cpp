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

#include "Network\Minecraft\Pong.h"
#include "Network\Minecraft\MinecraftPackets.h"

Pong::Pong(long pingID) : DataPacket(9)
{
	this->pingID = pingID;
}

Pong::Pong(Packet* packet) : DataPacket(packet) {}

void Pong::decode()
{
	if (this->getByte() != MinecraftPackets::PONG)
		return;

	this->pingID = this->getLong();
}

void Pong::encode()
{
	this->putByte(MinecraftPackets::PONG);
	this->putLong(this->pingID);
}
