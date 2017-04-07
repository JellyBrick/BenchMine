#include "UseItem.h"

UseItem::UseItem() : DataPacket(64) {
	blockID = 0;
	face = 0;
	hotbarSlot = 0;
}

void UseItem::decode() {
	++position; // Skip Packet ID
	blockPosition = Vector3i::deserialize(*this);
	blockID = getVarUInt();
	face = getVarUInt();
	facePosition = Vector3f::deserialize(*this);
	eventPosition = Vector3f::deserialize(*this);
	hotbarSlot = getVarUInt();
	// ItemStack::deserialize
}