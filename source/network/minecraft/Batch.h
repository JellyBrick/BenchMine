#pragma once

#include <memory>
#include <vector>

#include <packets/DataPacket.h>
#include <network/Packet.h>

class Batch : public RakLib::DataPacket {
public:
	static constexpr int32 DEFAULT_BUFFER_SIZE = RakLib::Packet::DEFAULT_BUFFER_SIZE * 2;

	std::vector<std::unique_ptr<RakLib::Packet>> packets;

public:
	Batch(std::unique_ptr<Packet>&& packet);
	Batch();
	~Batch();

	void encode() override;
	void decode() override;
};