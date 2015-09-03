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
#ifndef CUSTOM_PACKET_H_
#define CUSTOM_PACKET_H_

#include "InternalPacket.h"

class CustomPacket : public Packet
{
public:
	uint8_t PacketID;
	int sequenceNumber;
	std::vector<InternalPacket*> packets;

public:
	CustomPacket(Packet* packet);
	CustomPacket(uint8_t* data, int size);
	CustomPacket();
	

	int getLength();

	void decode();

	void encode();
};
#endif