#pragma once

#include <memory>
#include <vector>

#include <RakLib/protocol/DataPacket.h>
#include <RakLib/network/Packet.h>

class Batch : public RakLib::DataPacket {
public:
	static const uint32 DEFAULT_BUFFER_SIZE;

	std::vector<std::unique_ptr<RakLib::Packet>> packets;

public:
	Batch(std::unique_ptr<Packet>&& packet);
	Batch();
	~Batch();

	void encode() override;
	void decode() override;
};