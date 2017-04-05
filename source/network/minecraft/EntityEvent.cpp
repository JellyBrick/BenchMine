#include "EntityEvent.h"

#include "MinecraftPackets.h"

EntityEvent::EntityEvent() : DataPacket(16) {
	this->entityID = 0;
	this->event = 0x00;
	this->unknown = 0;
}

void EntityEvent::decode() {
	++this->position; // Skip Packet ID
	this->entityID = this->getVarULong();
	this->event = this->getByte();
	this->unknown = this->getVarUInt();
}

void EntityEvent::encode() {
	this->putByte((uint8)MinecraftPackets::EntityEvent);
	this->putVarULong(this->entityID);
	this->putByte(this->event);
	this->putVarUInt(this->unknown);
}