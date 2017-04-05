#pragma once

#include <packets/DataPacket.h>

#include "world/math/Vector3i.h"

class UpdateBlock : public RakLib::DataPacket {
public:
	static const int FLAG_NONE = 0;
	static const int FLAG_NEIGHBORS = 1;
	static const int FLAG_NETWORK = 2;
	static const int FLAG_NOGRAPHIC = 4;
	static const int FLAG_PRIORITY = 8;

	static const int FLAG_ALL = FLAG_NEIGHBORS | FLAG_NETWORK;
	static const int FLAG_ALL_PRIORITY = FLAG_ALL | FLAG_PRIORITY;

	Vector3i blockPosition;
	uint8 blockID;
	uint8 blockData;
	uint8 flags;

public:
	UpdateBlock();

	void encode() override;
};
