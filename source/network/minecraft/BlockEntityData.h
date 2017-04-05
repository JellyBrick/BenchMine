#pragma once

#include <packets/DataPacket.h>

#include "world/math/Vector3i.h"

class BlockEntityData : public RakLib::DataPacket {
public:
	Vector3i blockPosition;
	// NBTCompoundTag compoundTag;

public:
	BlockEntityData();

	void decode() override;

	void encode() override;
};