#pragma once

#include <memory>

#include <RakLib/network/Packet.h>
#include <RakLib/protocol/DataPacket.h>

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