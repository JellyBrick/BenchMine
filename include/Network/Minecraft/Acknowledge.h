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
#ifndef ACKNOWLEDGE_H_
#define ACKNOWLEDGE_H_

#include "../Packet.h"
#include <vector>
#include <algorithm>

class Acknowledge : public Packet
{
public:
	std::vector<int> sequenceNumbers;
	uint8_t pid; // ACK || NACK

public:
	Acknowledge(uint8_t pid, std::vector<int> sequenzeNum);
	Acknowledge(Packet* pck);

	void decode();
	void encode();

};

#endif