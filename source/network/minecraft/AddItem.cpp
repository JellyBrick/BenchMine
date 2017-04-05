#include "AddItem.h"

#include "MinecraftPackets.h"

// TODO: Remove placeholder packet size
AddItem::AddItem() : DataPacket(128) {}

void AddItem::encode() {
	this->putByte((uint8)MinecraftPackets::AddItem);
	// TODO: Do when an proper inventory system is implemented
}