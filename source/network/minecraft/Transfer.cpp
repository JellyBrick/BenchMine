#include "Transfer.h"

#include "MinecraftPackets.h"

Transfer::Transfer() : DataPacket(32) {
	serverPort = 19132;
}

void Transfer::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::Transfer));
	putVarString(serverAddress);
	putUShort(serverPort);
}