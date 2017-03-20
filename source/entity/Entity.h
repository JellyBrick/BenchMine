#pragma once

#include "..\math\Vector3f.h"

class Entity
{
public:
	static unsigned int entityIDs;

private:
	unsigned int id;
	
	Vector3f position, lastPosition;
	float yaw, pitch;

public:
	Entity();

	inline const Vector3f& getPosition() const { return this->position; }
	inline const Vector3f& getLastPosition() const { return this->lastPosition; };

	inline float getYaw() const { return this->yaw; };
	inline float getPitch() const { return this->pitch; };

};