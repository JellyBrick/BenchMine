#include "MobEffect.h"

#include "MinecraftPackets.h"

MobEffect::MobEffect() : DataPacket(64) {
	this->entityID = 0;
	this->eventID = Event::ADD;
	this->effectID = 0;
	this->amplifier = 0;
	this->particles = true;
	this->duration = 0;
}

void MobEffect::encode() {
	this->putByte((uint8)MinecraftPackets::MobEffect);
	this->putVarULong(this->entityID);
	this->putByte((uint8)this->eventID);
	this->putVarUInt(this->effectID);
	this->putVarUInt(this->amplifier);
	this->putBool(this->particles);
	this->putVarUInt(this->duration);
}