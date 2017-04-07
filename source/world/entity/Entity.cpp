#include "Entity.h"

uint64 Entity::entityIDs = 0;

Entity::Entity() {
	id = ++Entity::entityIDs;
	yaw = 0;
	pitch = 0;
}

void Entity::update() {
	// Nothing to do! For now...
}

void Entity::onRemove() {
	// Nothing to do! For now...
}
