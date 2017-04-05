#include "ShowCredits.h"

#include "MinecraftPackets.h"

ShowCredits::ShowCredits() : DataPacket(16) {
	this->entityID = 0;
	this->action = Action::START;
}

void ShowCredits::decode() {
	++this->position; // Skip Packet ID;
	this->entityID = this->getVarULong();
	this->action = (Action)this->getVarUInt();
}

void ShowCredits::encode() {
	this->putByte((uint8)MinecraftPackets::ShowCredits);
	this->putVarULong(this->entityID);
	this->putVarUInt((Action)this->action);
}