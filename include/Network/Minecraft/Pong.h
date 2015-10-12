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

#ifndef PONG_H_
#define PONG_H_

#include <RakLib\Packets\DataPacket.h>

class Pong : public RakLib::DataPacket
{
public:
	uint64 pingID;

	Pong(long pingID);
	Pong(Packet* pck);

	void decode();
	void encode();
};

#endif