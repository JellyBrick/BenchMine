#pragma once

#include <RakLib/Common.h>

#include "world/math/Vector3f.h"

class Entity {
public:
	static uint64 entityIDs;

protected:
	uint64 id;
	
	bool removed;
	
	Vector3f position, lastPosition;
	float yaw, bodyYaw, pitch;


public:
	Entity();

	virtual void update();
	virtual void onRemove();

	uint64 getID() const;

	void setRemoved(bool newValue = true);
	bool isRemoved() const;

	const Vector3f& getPosition() const;
	const Vector3f& getLastPosition() const;

	float getYaw() const;
	float getBodyYaw() const;
	float getPitch() const;
};