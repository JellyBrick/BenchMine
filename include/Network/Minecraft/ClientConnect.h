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

#ifndef CLIENT_CONNECT_H_
#define CLIENT_CONNECT_H_

#include <RakLib\Packets\DataPacket.h>

class ClientConnect : public RakLib::DataPacket
{
public:
	long clientID;
	long session;
	uint8 unknown;

public:
	ClientConnect(Packet* packet);

	void decode() override;
};
#endif