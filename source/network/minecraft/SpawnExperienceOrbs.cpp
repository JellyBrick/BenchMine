#include "SpawnExperienceOrb.h"

#include "MinecraftPackets.h"

SpawnExperienceOrb::SpawnExperienceOrb() : DataPacket(24) {
	this->amount = 0;
}

void SpawnExperienceOrb::encode() {
	this->putByte((uint8)MinecraftPackets::SpawnExperienceOrb);
	Vector3f::serialize(this->spawnPosition, *this);
	this->putVarUInt(this->amount);
}