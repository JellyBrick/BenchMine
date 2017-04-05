#pragma once

#include <packets/DataPacket.h>

#include "world/math/Vector3i.h"

class CommandBlockUpdate : public RakLib::DataPacket {
public:
	bool isBlock;
	Vector3i blockPosition;
	uint32 commandBlockMode;
	bool isRedstoneMode;
	bool isConditionalMode;

	uint64 minecartEntityID;

	std::string command;
	std::string lastCommandOutput;
	std::string name;

	bool shouldTrackOutput;

public:
	CommandBlockUpdate();

	void decode() override;

	void encode() override;
};