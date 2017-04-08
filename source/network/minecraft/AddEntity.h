#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3f.h"

class AddEntity : public RakLib::DataPacket {
public:
	uint64 entityID;
	uint32 entityType;
	Vector3f entityPosition;
	Vector3f entityMotion;
	f32 pitch;
	f32 yaw;
	// EntityAttributes
	// EntityMetadata
	// EntityLinks
public:
	AddEntity();

	void encode() override;
};