#include "Transfer.h"

#include "MinecraftPackets.h"

Transfer::Transfer() : DataPacket(32) {
	this->serverPort = 19132;
}

void Transfer::encode() {
	this->putByte((uint8)MinecraftPackets::Transfer);
	this->putVarString(this->serverAddress);
	this->putUShort(this->serverPort);
}