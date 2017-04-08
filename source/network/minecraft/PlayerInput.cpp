#include "PlayerInput.h"

PlayerInput::PlayerInput()  : DataPacket(16){
	motionX = 0.0f;
	motionY = 0.0f;
	unknown1 = false;
	unknown2 = false;
}

void PlayerInput::decode() {
	++position; // Skip Packet ID
	motionX = getFloat();
	motionY = getFloat();
	unknown1 = getBool();
	unknown2 = getBool();
}
