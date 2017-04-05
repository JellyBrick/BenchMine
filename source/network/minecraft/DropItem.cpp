#include "DropItem.h"

// TODO: Implement proprly when an proper Inventory System is implemented
DropItem::DropItem() : DataPacket(32) {
	this->type = 0x00;
}

void DropItem::decode() {
	++this->position; // Skip Packet ID
	this->type = this->getByte();
	// ItemStack::deserialize
}