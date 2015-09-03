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

#ifndef INTERNAL_PACKET_H_
#define INTERNAL_PACKET_H_

#include <vector>
#include <algorithm>
#include <iterator>

#include "../Packet.h"

class InternalPacket{
public:
	uint8_t* buff;
	int length;
	uint8_t reliability = -1;
	bool hasSplit = false;
	int messageIndex = -1;
	int orderIndex = -1;
	uint8_t orderChannel = (uint8_t) 0xff;
	int splitCount = -1;
	short splitID = -1;
	int splitIndex = -1;

public:

	int getLength();
	Packet* toBinary();
	static std::vector<InternalPacket*> fromBinary(uint8_t* buffer, int size);
	void Close();
};
#endif