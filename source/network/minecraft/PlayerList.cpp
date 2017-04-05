#include "PlayerList.h"

#include "MinecraftPackets.h"

PlayerList::PlayerList() : DataPacket(128) {
	this->type = ADD;
}

void PlayerList::encode() {
	this->putByte((uint8)MinecraftPackets::PlayerList);
	this->putByte((uint8)this->type);
	// TODO: Serialize Entries
}