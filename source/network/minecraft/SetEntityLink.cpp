#include "SetEntityLink.h"

#include "MinecraftPackets.h"

SetEntityLink::SetEntityLink() : DataPacket(16) {
	from = 0;
	to = 0;
	type = 0x00;
}

void SetEntityLink::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::SetEntityLink));
	putVarULong(from);
	putVarULong(to);
	putByte(type);
}