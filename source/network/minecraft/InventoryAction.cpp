#include "InventoryAction.h"

#include "MinecraftPackets.h"

InventoryAction::InventoryAction() : DataPacket(32) {
	this->unknown = 0;
}

void InventoryAction::encode() {
	this->putByte((uint8)MinecraftPackets::InventoryAction);
	this->putVarUInt(unknown);
	// ItemStack::serialize
}