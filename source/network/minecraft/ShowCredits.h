#pragma once

#include <RakLib/protocol/DataPacket.h>

class ShowCredits : public RakLib::DataPacket {
public:
	enum Action {
		START,
		END
	};

	uint64 entityID;
	Action action;

public:
	ShowCredits();

	void decode() override;

	void encode() override;
};