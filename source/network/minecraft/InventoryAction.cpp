#include "InventoryAction.h"

#include "MinecraftPackets.h"

InventoryAction::InventoryAction() : DataPacket(32) {
	unknown = 0;
}

void InventoryAction::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::InventoryAction));
	putVarUInt(unknown);
	// ItemStack::serialize
}