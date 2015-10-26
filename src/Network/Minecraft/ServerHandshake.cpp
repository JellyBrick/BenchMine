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
#include "Network\Minecraft\ServerHandshake.h"
#include "Utils.h"

ServerHandshake::ServerHandshake(const std::string& ip, uint16 port, long sendPing, long sendPong) : DataPacket(96) {
	this->ip = ip;
	this->port = port;
	this->sendPing = sendPing;
	this->sendPong = sendPong;
}

void ServerHandshake::encode() {
	this->putByte(MinecraftPackets::SERVER_HANDSHAKE);
	this->putAddress(this->ip.c_str(), (uint16)this->port);
	this->putShort(0);

	this->putAddress("127.0.0.1", 0);
	for (int i = 0; i < 9; i++) {
		this->putAddress("0.0.0.0", 0);
	}
	
	this->putLong(this->sendPing);
	this->putLong(this->sendPong);

}

void ServerHandshake::putAddress(const char* address, short port) {
	this->putByte(4); // This should be the version of the ip. IPV4(4) or IPV6(6)
	std::vector<std::string> numbers = Utils::explode(address, '.');
	for (const auto& it : numbers) {
		this->putChar((~(atoi(it.c_str()))) & 0xff);
	}
	this->putShort(port);
}