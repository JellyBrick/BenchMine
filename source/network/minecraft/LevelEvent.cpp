#include "LevelEvent.h"

#include "MinecraftPackets.h"

LevelEvent::LevelEvent() : DataPacket(32) {
	this->eventID = Event::NONE;
	this->data = 0;
}

void LevelEvent::encode() {
	this->putByte((uint8)MinecraftPackets::LevelEvent);
	this->putVarUInt((uint32)this->eventID);
	Vector3f::serialize(this->eventPosition, *this);
	this->putVarUInt(this->data);
}