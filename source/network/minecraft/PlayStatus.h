#pragma once

#include <packets\DataPacket.h>

class PlayStatus : public RakLib::DataPacket
{
public:
	int status;

public:
	PlayStatus(int status);
	void encode() override;

};

