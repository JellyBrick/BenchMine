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

#ifndef DATA_PACKET_H_
#define DATA_PACKET_H_

#include "../Packet.h"
#include "InternalPacket.h"
#include "MinecraftPackets.h"

class DataPacket : public Packet {
public:
	inline DataPacket() {}
	inline DataPacket(InternalPacket* pck) {
		this->buffer = pck->buff;
		this->length = pck->length;
		this->position = 0;
	}
	inline DataPacket(int size) : Packet(size) {}

	virtual void encode() = 0;
	virtual void decode() = 0;
};
#endif