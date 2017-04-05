#include "StopSound.h"

#include "MinecraftPackets.h"

StopSound::StopSound() : DataPacket(64) {
	this->stopAll = false;
}

void StopSound::decode() {
	++this->position; // Skip Packet ID
	this->songID = this->getVarString();
	this->stopAll = this->getBool();
}

void StopSound::encode() {
	this->putByte((uint8)MinecraftPackets::StopSound);
	this->putVarString(this->songID);
	this->putBool(this->stopAll);
}