#include "PlaySound.h"

#include "MinecraftPackets.h"

PlaySound::PlaySound() : DataPacket(64){
	this->unknown1 = 0.0f;
	this->unknown2 = 0.0f;
}

void PlaySound::decode() {
	++this->position; // Skip Packet ID
	this->soundID = this->getVarString();
	this->eventPosition = Vector3i::deserialize(*this);
	this->unknown1 = this->getFloat();
	this->unknown2 = this->getFloat();
}

void PlaySound::encode() {
	this->putByte((uint8)MinecraftPackets::PlaySound);
	this->putVarString(this->soundID);
	Vector3i::serialize(this->eventPosition, *this);
	this->putFloat(this->unknown1);
	this->putFloat(this->unknown2);
}