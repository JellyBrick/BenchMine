#pragma once

#include <packets/DataPacket.h>

class StopSound : public RakLib::DataPacket {
public:
	std::string songID;
	bool stopAll;

public:
	StopSound();

	void decode() override;

	void encode() override;
};