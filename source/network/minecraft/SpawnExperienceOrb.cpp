#include "SpawnExperienceOrb.h"

#include "MinecraftPackets.h"

SpawnExperienceOrb::SpawnExperienceOrb() : DataPacket(24) {
	amount = 0;
}

void SpawnExperienceOrb::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::SpawnExperienceOrb));
	Vector3f::serialize(spawnPosition, *this);
	putVarUInt(amount);
}