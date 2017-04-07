#include "SetHealth.h"

#include "MinecraftPackets.h"

SetHealth::SetHealth()  : DataPacket(8) {
	health = 0;
}

void SetHealth::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::SetHealth));
	putVarUInt(health);
}