#include "Interact.h"

#include "MinecraftPackets.h"

Interact::Interact() : DataPacket(16) {
	this->action = Action::NONE;
	this->entityID = 0;
}

void Interact::decode() {
	++this->position; // Skip Packet ID
	this->action = (Action)this->getByte();
	this->entityID = this->getVarULong();
}

void Interact::encode() {
	this->putByte((uint8)MinecraftPackets::Interact);
	this->putByte((uint8)this->action);
	this->putVarULong(this->entityID);
}