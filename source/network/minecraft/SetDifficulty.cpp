#include "SetDifficulty.h"

#include "MinecraftPackets.h"

SetDifficulty::SetDifficulty() : DataPacket(8) {
	this->difficulty = 0;
}

void SetDifficulty::encode() {
	this->putByte((uint8)MinecraftPackets::SetDifficulty);
	this->putVarUInt(this->difficulty);
}