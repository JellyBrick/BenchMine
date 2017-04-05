#include "PlayerInput.h"

PlayerInput::PlayerInput()  : DataPacket(16){
	this->motionX = 0.0f;
	this->motionY = 0.0f;
	this->unknown1 = false;
	this->unknown2 = false;
}

void PlayerInput::decode() {
	++this->position; // Skip Packet ID
	this->motionX = this->getFloat();
	this->motionY = this->getFloat();
	this->unknown1 = this->getBool();
	this->unknown2 = this->getBool();
}
