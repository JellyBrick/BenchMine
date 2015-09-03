#ifndef PONG_H_
#define PONG_H_

#include "DataPacket.h"

class Pong : public DataPacket
{
public:
	long pingId;
	long pongId;

	Pong(long pingID);

	void decode();
	void encode();
};

#endif