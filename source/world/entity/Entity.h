#pragma once

#include <Common.h>

#include "world/math/Vector3f.h"

class Entity {
public:
	static uint64 entityIDs;

protected:
	uint64 id;
	
	Vector3f position, lastPosition;
	float yaw, pitch;

public:
	Entity();

	const Vector3f& getPosition() const { return this->position; }
	const Vector3f& getLastPosition() const { return this->lastPosition; }

	float getYaw() const { return this->yaw; }
	float getPitch() const { return this->pitch; }

};