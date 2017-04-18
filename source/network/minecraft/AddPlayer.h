#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3f.h"

class AddPlayer : public RakLib::DataPacket {
public:
	std::string UUID;
	std::string username;
	uint64 entityID;
	Vector3f entityPosition;
	Vector3f entityMotion;
	f32 pitch;
	f32 headYaw;
	f32 yaw;
	//ItemStack
	//EntityMetadata

public:
	AddPlayer();

	void encode() override;
};