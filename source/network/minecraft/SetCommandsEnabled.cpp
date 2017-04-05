#include "SetCommandsEnabled.h"
#include "MinecraftPackets.h"

SetCommandsEnabled::SetCommandsEnabled() : DataPacket(4) {
	this->enabled = true;
}

void SetCommandsEnabled::encode() {
	this->putByte((uint8)MinecraftPackets::SetCommandsEnabled);
	this->putBool(this->enabled);
}