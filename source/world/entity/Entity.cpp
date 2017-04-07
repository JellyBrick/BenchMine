#include "Entity.h"

uint64 Entity::entityIDs = 0;

Entity::Entity() {
	id = ++Entity::entityIDs;
	yaw = 0;
	pitch = 0;
}