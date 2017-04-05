#pragma once

#include <packets/DataPacket.h>

class MapInfoRequest : public RakLib::DataPacket {
public:
	uint64 mapID;

public:
	MapInfoRequest();

	void encode() override;
};