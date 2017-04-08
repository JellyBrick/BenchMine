#pragma once

#include <vector>

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector3f.h"
#include "world/math/Vector3i.h"

class Explode : public RakLib::DataPacket {
public:
	Vector3f explosionPosition;
	f32 radius;
	std::vector<Vector3i> records;

public:
	Explode();

	void encode() override;
};