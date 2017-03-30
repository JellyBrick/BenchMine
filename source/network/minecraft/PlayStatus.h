#pragma once

#include <packets\DataPacket.h>

class PlayStatus : public RakLib::DataPacket
{
public:
	enum STATUS {
		LOGIN_SUCCESS,
		CLIENT_OUTDATED,
		SERVER_OUTDATED,
		START_GAME
	};

	int status;

public:
	PlayStatus(int status);
	void encode() override;
};

