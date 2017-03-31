#pragma once

#include <memory>
#include <vector>

#include <packets/DataPacket.h>
#include <network/Packet.h>

class Batch : public RakLib::DataPacket {
public:
	std::vector<std::unique_ptr<RakLib::Packet>> packets;

public:
	Batch(std::unique_ptr<Packet>&& packet);
	Batch();
	~Batch();

	void encode() override;
	void decode() override;
};