#pragma once

#include <memory>

#include <network/Packet.h>
#include <packets/DataPacket.h>

class Ping : public RakLib::DataPacket
{
public:
	int64 pingID;

public:
	Ping(std::unique_ptr<RakLib::Packet>&& packet);
	Ping(int64 pingID);

	void encode() override;
	void decode() override;
};