#pragma once

#include <packets\DataPacket.h>

class Pong : public RakLib::DataPacket
{
public:
	int64 pingID;

	Pong(int64 pingID);
	Pong(Packet* pck);

	void decode();
	void encode();
};
