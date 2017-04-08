#include "Entity.h"

uint64 Entity::entityIDs = 0;

Entity::Entity() : removed(false), yaw(0.0f), bodyYaw(0.0f), pitch(0.0f) {
	id = ++Entity::entityIDs;
}

void Entity::update() {
	// Nothing to do! For now...
}

void Entity::onRemove() {
	// Nothing to do! For now...
}

uint64 Entity::getID() const {
	return id;
}

void Entity::setRemoved(bool newValue) {
	removed = newValue;
}

bool Entity::isRemoved() const {
	return removed;
}

const Vector3f& Entity::getPosition() const {
	return position;
}

const Vector3f& Entity::getLastPosition() const {
	return lastPosition;
}

float Entity::getYaw() const {
	return yaw;
}

float Entity::getBodyYaw() const {
	return bodyYaw;
}

float Entity::getPitch() const {
	return pitch;
}