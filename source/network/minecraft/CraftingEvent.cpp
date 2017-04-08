#include "CraftingEvent.h"

// TODO: Implement properly when an propert Inventory system is implemented
CraftingEvent::CraftingEvent() : DataPacket(512) {
	windowID = 0;
	type = 0;
}

void CraftingEvent::decode() {
	++position; // Skip Packet ID
	windowID = getByte();
	type = getVarUInt();
	// UUID::deserialize
	// Input - ItemStack::deserialize
	// Output - ItemStack::deserialize
}