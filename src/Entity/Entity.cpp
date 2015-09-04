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

#include "Entity/Entity.h"

unsigned int Entity::entityIDs = 1;

Entity::Entity()
{
	this->id = Entity::entityIDs++;
	this->position = Vector3f();
	this->lastPosition = Vector3f();
	this->yaw = 0;
	this->pitch = 0;
}
