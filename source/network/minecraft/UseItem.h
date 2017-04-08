#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3f.h"
#include "world/math/Vector3i.h"

class UseItem : public RakLib::DataPacket {
public:
	Vector3i blockPosition;
	uint32 blockID;
	uint32 face;
	Vector3f facePosition;
	Vector3f eventPosition;
	//ItemStack handItem;
	uint32 hotbarSlot;

public:
	UseItem();

	void decode() override;
};