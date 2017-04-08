#pragma once

#include <memory>

#include <RakLib/network/Packet.h>
#include <RakLib/protocol/DataPacket.h>

class RequestChunkData : public RakLib::DataPacket {
public:
	int32 radius;

public:
	RequestChunkData(std::unique_ptr<RakLib::Packet>&& packet);

	void decode() override;
};