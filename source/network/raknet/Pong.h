#pragma once

#include <packets\DataPacket.h>

class Pong : public RakLib::DataPacket
{
public:
	int64 pingID;

	Pong(int64 pingID);
	Pong(std::unique_ptr<Packet>&& packet);

	void decode() override;
	void encode() override;
};
