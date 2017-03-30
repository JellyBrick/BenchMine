#include "PlayStatus.h"

#include <network/Swap.h>

#include "MinecraftPackets.h"
#include "network/raknet/RaknetPackets.h"

PlayStatus::PlayStatus(int status) : DataPacket(6) {
	this->status = status;
}

void PlayStatus::encode() {
	this->putByte((uint8)RaknetPacket::WRAPPER);
	this->putByte((uint8)MinecraftPackets::PLAY_STATUS);
	this->putInt(this->status);
}
