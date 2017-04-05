#include "SetGameMode.h"

#include "MinecraftPackets.h"

SetGameMode::SetGameMode() : DataPacket(8) {
	this->gamemode = 0;
}

void SetGameMode::encode() {
	this->putByte((uint8)MinecraftPackets::SetGameMode);
	this->putVarUInt(this->gamemode);
}