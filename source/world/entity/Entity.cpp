#include "Entity.h"

uint64 Entity::entityIDs = 0;

Entity::Entity() {
	this->id = ++Entity::entityIDs;
	this->yaw = 0;
	this->pitch = 0;
}
