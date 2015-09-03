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

#ifndef SERVER_HANDSHAKE_H_
#define SERVER_HANDSHAKE_H_

#include "DataPacket.h"

class ServerHandshake : public DataPacket
{
public:
	int port;
	long sessionID;

public:
	ServerHandshake(int port, long session);
	void decode();
	void encode();
	void putDataArray();
};
#endif