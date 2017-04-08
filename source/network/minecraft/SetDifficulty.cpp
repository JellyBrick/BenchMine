#include "SetDifficulty.h"

#include "MinecraftPackets.h"

SetDifficulty::SetDifficulty() : DataPacket(8) {
	difficulty = 0;
}

void SetDifficulty::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::SetDifficulty));
	putVarUInt(difficulty);
}