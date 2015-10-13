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

#include "Network\Minecraft\MinecraftPackets.h"
#include "Network\Minecraft\Ping.h"

Ping::Ping(Packet* pck) : DataPacket(pck) {
	this->pingID = 0;
}

Ping::Ping(uint64 pingID) : DataPacket(9) {
	this->pingID = pingID;
}

void Ping::decode() {
	if (this->getByte() != MinecraftPackets::PING)
		return;

	this->pingID = this->getLong();
}

void Ping::encode() {
	this->putByte(MinecraftPackets::PING);
	this->putLong(this->pingID);
}