#pragma once

#include <memory>

#include <network/Packet.h>
#include <packets/DataPacket.h>

class RequestChunkData : public RakLib::DataPacket {
public:
	int32 radius;

public:
	RequestChunkData(std::unique_ptr<RakLib::Packet>&& packet);

	void decode() override;
};