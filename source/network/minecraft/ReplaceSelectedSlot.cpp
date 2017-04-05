#include "ReplaceSelectedSlot.h"

#include "MinecraftPackets.h"

// TODO: Implement properly when an proper Inventory system is implemented
ReplaceSelectedSlot::ReplaceSelectedSlot() : DataPacket(16) {}

void ReplaceSelectedSlot::encode() {
	this->putByte((uint8)MinecraftPackets::ReplaceSelectedItem);
	// ItemStack::serialize
}
