#include "UseItem.h"

UseItem::UseItem() : DataPacket(64) {
	this->blockID = 0;
	this->face = 0;
	this->hotbarSlot = 0;
}

void UseItem::decode() {
	++this->position; // Skip Packet ID
	this->blockPosition = Vector3i::deserialize(*this);
	this->blockID = this->getVarUInt();
	this->face = this->getVarUInt();
	this->facePosition = Vector3f::deserialize(*this);
	this->eventPosition = Vector3f::deserialize(*this);
	this->hotbarSlot = this->getVarUInt();
	// ItemStack::deserialize
}