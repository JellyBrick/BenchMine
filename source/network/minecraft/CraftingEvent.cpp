#include "CraftingEvent.h"

// TODO: Implement properly when an propert Inventory system is implemented
CraftingEvent::CraftingEvent() : DataPacket(512) {
	this->windowID = 0;
	this->type = 0;
}

void CraftingEvent::decode() {
	++this->position; // Skip Packet ID
	this->windowID = this->getByte();
	this->type = this->getVarUInt();
	// UUID::deserialize
	// Input - ItemStack::deserialize
	// Output - ItemStack::deserialize
}