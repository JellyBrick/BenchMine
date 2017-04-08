#include "PlayerList.h"

#include "MinecraftPackets.h"

PlayerList::PlayerList() : DataPacket(128) {
	type = ADD;
}

void PlayerList::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::PlayerList));
	putByte(static_cast<uint8>(type));
	// TODO: Serialize Entries
}