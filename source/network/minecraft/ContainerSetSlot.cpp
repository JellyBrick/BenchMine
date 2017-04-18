#include "ContainerSetSlot.h"

#include "MinecraftPackets.h"

// TODO: Finish implementation, when an proper inventory system is implemented 
ContainerSetSlot::ContainerSetSlot() : DataPacket(32) {
	windowsID = 0x00;
	slot = 0;
	hotbarSlot = 0;
	selectedSlot = 0x00;
}

void ContainerSetSlot::decode() {
	++position; // Skip Packet ID
	windowsID = getByte();
	slot = getVarUInt();
	hotbarSlot = getVarUInt();
	// ItemStack::deserialize
	selectedSlot = getByte();
}

void ContainerSetSlot::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ContainerSetSlot));
	putByte(windowsID);
	putVarUInt(slot);
	putVarUInt(hotbarSlot);
	// ItemStack::serialize
	putByte(selectedSlot);
}