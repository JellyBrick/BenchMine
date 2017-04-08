#pragma once

#include <RakLib/protocol/DataPacket.h>

class UpdateAttributes : public RakLib::DataPacket {
public:
	uint64 entityID;
	//std::vector<EntityAttributes> attributes

public:
	UpdateAttributes();

	void encode() override;
};