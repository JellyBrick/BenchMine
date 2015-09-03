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
#ifndef PING_H_
#define PING_H_

#include "DataPacket.h"

class Ping : public DataPacket
{
public:
	long pingID;

public:
	Ping(InternalPacket* pck);

	void encode();
	void decode();
};
#endif