#pragma once

#include <packets\DataPacket.h>

class Ping : public RakLib::DataPacket
{
public:
	int64 pingID;

public:
	Ping(Packet*);
	Ping(int64 pingID);

	void encode() override;
	void decode() override;
};