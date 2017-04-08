#include "SetSpawnPosition.h"

#include "MinecraftPackets.h"

SetSpawnPosition::SetSpawnPosition() : DataPacket(64) {
	unknown1 = 0;
	unknown2 = false;
}

void SetSpawnPosition::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::SetSpawnPosition));
	putVarUInt(unknown1);
	Vector3i::serialize(spawnPosition, *this);
	putBool(unknown2);
}