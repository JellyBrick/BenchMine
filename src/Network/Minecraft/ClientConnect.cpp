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

#include "Network\Minecraft\ClientConnect.h"
#include "Network\Minecraft\MinecraftPackets.h"

ClientConnect::ClientConnect(Packet* packet) : DataPacket(packet) {
	this->clientID = 0;
	this->sendPing = 0;
	this->useSecurity = 0x00;
}

void ClientConnect::decode() {
	if (this->getByte() != MinecraftPackets::CLIENT_CONNECT) {
		throw std::runtime_error("Expected another packet!");
	}

	this->clientID = this->getLong();
	this->sendPing = this->getLong();
	this->useSecurity = ((this->getByte() == 0x01) ? true : false);
}
