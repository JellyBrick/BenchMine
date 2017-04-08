#include "SetTime.h"

#include "MinecraftPackets.h"

SetTime::SetTime(int32 time, bool started) : DataPacket(6) {
	levelTime = time;
	haveStarted = started;
}

void SetTime::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::SetTime));
	putVarUInt(static_cast<int32>(levelTime));
	putBool(haveStarted);
}