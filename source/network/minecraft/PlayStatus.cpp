#include "PlayStatus.h"

#include <network/Swap.h>

#include "MinecraftPackets.h"

PlayStatus::PlayStatus(int status) : DataPacket(5) {
	this->status = status;
}

void PlayStatus::encode() {
	this->putByte((uint8)MinecraftPackets::PlayStatus);
	this->putInt(this->status);
}
