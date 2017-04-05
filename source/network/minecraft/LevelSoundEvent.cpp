#include "LevelSoundEvent.h"

#include "MinecraftPackets.h"

LevelSoundEvent::LevelSoundEvent() : DataPacket(32) {
	this->eventID = Event::UNDEFINED;
	this->extraData = 0;
	this->pitch = 0;
	this->unknown1 = false;
	this->unknown2 = false;
}

void LevelSoundEvent::decode() {
	++this->position; // Skip Packet ID
	this->eventID = (Event)this->getByte();
	this->eventPosition = Vector3f::deserialize(*this);
	this->extraData = this->getVarUInt();
	this->pitch = this->getVarUInt();
	this->unknown1 = this->getBool();
	this->unknown2 = this->getBool();
}

void LevelSoundEvent::encode() {
	this->putByte((uint8)MinecraftPackets::LevelSoundEvent);
	this->putByte((uint8)this->eventID);
	Vector3f::serialize(this->eventPosition, *this);
	this->putVarUInt(this->extraData);
	this->putVarUInt(this->pitch);
	this->putBool(this->unknown1);
	this->putBool(this->unknown2);
}
