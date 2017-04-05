#pragma once

#include <packets\DataPacket.h>

class Pong : public RakLib::DataPacket
{
public:
	uint64 pingID;

	Pong(uint64 pingID);
	Pong(std::unique_ptr<Packet>&& packet);

	void decode() override;
	void encode() override;
};
