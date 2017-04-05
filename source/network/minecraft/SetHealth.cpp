#include "SetHealth.h"

#include "MinecraftPackets.h"

SetHealth::SetHealth()  : DataPacket(8) {
	this->health = 0;
}

void SetHealth::encode() {
	this->putByte((uint8)MinecraftPackets::SetHealth);
	this->putVarUInt(this->health);
}
