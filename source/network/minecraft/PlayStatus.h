#pragma once

#include <packets\DataPacket.h>

class PlayStatus : public RakLib::DataPacket
{
public:
	enum STATUS {
		LOGIN_SUCCESS,
		CLIENT_OUTDATED,
		SERVER_OUTDATED,
		SPAWN
	};

	int status;

public:
	PlayStatus(int playStatus);
	void encode() override;
};

