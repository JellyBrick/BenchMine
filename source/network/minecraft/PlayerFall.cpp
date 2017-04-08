#include "PlayerFall.h"

PlayerFall::PlayerFall() : DataPacket(8) {
	fallDistance = 0.0f;
}

void PlayerFall::decode() {
	++position; // Skip Packet ID
	fallDistance = getFloat();
}