#include "SetGameMode.h"

#include "MinecraftPackets.h"

SetGameMode::SetGameMode() : DataPacket(8) {
	gamemode = 0;
}

void SetGameMode::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::SetGameMode));
	putVarUInt(gamemode);
}