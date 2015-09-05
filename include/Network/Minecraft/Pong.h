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