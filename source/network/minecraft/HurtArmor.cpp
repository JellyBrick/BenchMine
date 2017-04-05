#include "HurtArmor.h"

#include "MinecraftPackets.h"

HurtArmor::HurtArmor() : DataPacket(8) {
	health = 0;
}

void HurtArmor::encode() {
	this->putByte((uint8)MinecraftPackets::HurtArmor);
	this->putVarUInt(this->health);
}