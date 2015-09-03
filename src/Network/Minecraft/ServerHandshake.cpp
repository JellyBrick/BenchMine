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
#include "Network/Minecraft/ServerHandshake.h"
ServerHandshake::ServerHandshake(int port, long session) : DataPacket(96)
{
	this->port = port;
	this->sessionID = session;
}

void ServerHandshake::decode()
{
	//Not Used
}

void ServerHandshake::encode()
{
	this->putByte(MinecraftPackets::SERVER_HANDSHAKE);
	this->putByte(new uint8_t [4] { 0x04, 0x3f, 0x57, (uint8_t) 0xfe }, 4); //Cookie
	this->putByte((uint8_t) 0xcd); //Security flags
	this->putShort((short) port);
	putDataArray();
	this->putShort(0);
	this->putLong(sessionID);
	this->putByte(new uint8_t [8]{0x00, 0x00, 0x00, 0x00, 0x04, 0x44, 0x0b, (uint8_t) 0xa9}, 8);
}

void ServerHandshake::putDataArray()
{
	uint8_t* unknown1 = new uint8_t [4] { (uint8_t) 0xf5, (uint8_t) 0xff, (uint8_t) 0xff, (uint8_t) 0xf5 };
	uint8_t* unknown2 = new uint8_t [4] { (uint8_t) 0xff, (uint8_t) 0xff, (uint8_t) 0xff, (uint8_t) 0xff };

	this->putLTriad(4);
	this->putByte(unknown1, 4);

	for (int i = 0; i < 9; i++)
	{
		this->putTriad(4);
		this->putByte(unknown2, 4);
	}
}