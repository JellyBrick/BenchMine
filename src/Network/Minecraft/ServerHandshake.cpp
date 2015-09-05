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

#include "Network\Minecraft\ServerHandshake.h"
#include "Network\Minecraft\MinecraftPackets.h"

ServerHandshake::ServerHandshake(int port, long session) : DataPacket(96)
{
	this->port = port;
	this->sessionID = session;
}

void ServerHandshake::encode()
{
	this->putByte(MinecraftPackets::SERVER_HANDSHAKE);
	this->putByte(new uint8 [4] { 0x04, 0x3f, 0x57, (uint8) 0xfe }, 4); //Cookie
	this->putByte((uint8) 0xcd); //Security flags
	this->putShort((short) port);

	putDataArray();

	this->putShort(0);
	this->putLong(sessionID);
	this->putByte(new uint8 [8] { 0x00, 0x00, 0x00, 0x00, 0x04, 0x44, 0x0b, (uint8) 0xa9 }, 8);
}

void ServerHandshake::putDataArray()
{
	uint8* unknown1 = new uint8 [4] { (uint8) 0xf5, (uint8) 0xff, (uint8) 0xff, (uint8) 0xf5 };
	uint8* unknown2 = new uint8 [4] { (uint8) 0xff, (uint8) 0xff, (uint8) 0xff, (uint8) 0xff };

	this->putLTriad(4);
	this->putByte(unknown1, 4);

	for (int i = 0; i < 9; i++)
	{
		this->putTriad(4);
		this->putByte(unknown2, 4);
	}
}