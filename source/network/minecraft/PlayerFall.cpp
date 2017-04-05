#include "PlayerFall.h"

PlayerFall::PlayerFall() : DataPacket(8) {
	this->fallDistance = 0.0f;
}

void PlayerFall::decode() {
	++this->position; // Skip Packet ID
	this->fallDistance = this->getFloat();
}