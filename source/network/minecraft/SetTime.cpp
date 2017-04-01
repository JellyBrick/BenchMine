#include "SetTime.h"
#include "MinecraftPackets.h"

SetTime::SetTime(int32 time, bool started) : DataPacket(6) {
	this->levelTime = time;
	this->haveStarted = started;
}

void SetTime::encode() {
	this->putByte((uint8)MinecraftPackets::SetTime);
	this->putVarUInt((int32)this->levelTime);
	this->putBool(this->haveStarted);
}

