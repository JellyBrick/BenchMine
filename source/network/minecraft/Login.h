#pragma once

#include <packets\DataPacket.h>

class Login : public RakLib::DataPacket
{
public:
	int32 protocol;
	uint8 edition;
	uint8* payload;

public:
	Login(std::unique_ptr<Packet>&& packet);
	void decode() override;
};
