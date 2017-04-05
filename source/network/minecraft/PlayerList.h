#pragma once

#include <packets/DataPacket.h>

class PlayerList : public RakLib::DataPacket {
public:
	enum Type {
		ADD,
		REMOVE
	};

	Type type;
	// std::vector<Entry> entries;

public:
	PlayerList();

	void encode() override;
};