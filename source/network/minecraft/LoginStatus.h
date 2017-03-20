#pragma once

#include <packets\DataPacket.h>

class LoginStatus : public RakLib::DataPacket
{
public:
	int status;

public:
	LoginStatus(int status);
	void encode() override;

};

