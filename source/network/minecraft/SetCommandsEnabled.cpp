#include "SetCommandsEnabled.h"

#include "MinecraftPackets.h"

SetCommandsEnabled::SetCommandsEnabled() : DataPacket(4) {
	enabled = true;
}

void SetCommandsEnabled::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::SetCommandsEnabled));
	putBool(enabled);
}