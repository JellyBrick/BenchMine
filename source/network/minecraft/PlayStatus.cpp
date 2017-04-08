#include "PlayStatus.h"

#include <RakLib/network/Swap.h>

#include "MinecraftPackets.h"

PlayStatus::PlayStatus(int playStatus) : DataPacket(5), status(playStatus){}

void PlayStatus::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::PlayStatus));
	putInt(status);
}