/**
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* @author InusualZ
*
*
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include "Math\Vector3f.h"

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
#endif