#include "ItemFrameDropItem.h"

ItemFrameDropItem::ItemFrameDropItem() : DataPacket(16) {}

void ItemFrameDropItem::decode() {
	++position; // Skip Packet ID
	blockPosition = Vector3i::deserialize(*this);
}