#pragma once
#include <packets/DataPacket.h>
class ClientHandshake : public RakLib::DataPacket {
public:
	ClientHandshake(std::unique_ptr<Packet> packet);
	void decode() override;
};

