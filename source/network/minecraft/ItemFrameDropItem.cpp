#include "ItemFrameDropItem.h"

ItemFrameDropItem::ItemFrameDropItem() : DataPacket(16) {}

void ItemFrameDropItem::decode() {
	++this->position; // Skip Packet ID
	this->blockPosition = Vector3i::deserialize(*this);
}