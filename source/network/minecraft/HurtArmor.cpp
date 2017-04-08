#include "HurtArmor.h"

#include "MinecraftPackets.h"

HurtArmor::HurtArmor() : DataPacket(8) {
	health = 0;
}

void HurtArmor::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::HurtArmor));
	putVarUInt(health);
}