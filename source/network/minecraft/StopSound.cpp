#include "StopSound.h"

#include "MinecraftPackets.h"

StopSound::StopSound() : DataPacket(64) {
	stopAll = false;
}

void StopSound::decode() {
	++position; // Skip Packet ID
	songID = getVarString();
	stopAll = getBool();
}

void StopSound::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::StopSound));
	putVarString(songID);
	putBool(stopAll);
}