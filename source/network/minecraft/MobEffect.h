#pragma once

#include <RakLib/protocol/DataPacket.h>

class MobEffect : public RakLib::DataPacket {
public:
	enum class Event {
		ADD,
		MODIFY,
		REMOVE
	};

	uint64 entityID;
	Event eventID;
	uint32 effectID;
	uint32 amplifier;
	bool particles;
	uint32 duration;

public:
	MobEffect();

	void encode() override;
};