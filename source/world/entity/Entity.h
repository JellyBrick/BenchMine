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

	virtual void update();
	virtual void onRemove();

	const Vector3f& getPosition() const { return position; }
	const Vector3f& getLastPosition() const { return lastPosition; }

	float getYaw() const { return yaw; }
	float getPitch() const { return pitch; }
};