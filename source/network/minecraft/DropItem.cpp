#include "DropItem.h"

// TODO: Implement proprly when an proper Inventory System is implemented
DropItem::DropItem() : DataPacket(32) {
	type = 0x00;
}

void DropItem::decode() {
	++position; // Skip Packet ID
	type = getByte();
	// ItemStack::deserialize
}