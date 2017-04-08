#include "MobEquipment.h"

#include "MinecraftPackets.h"

MobEquipment::MobEquipment() : DataPacket(32) {
	entityID = 0;
	inventorySlot = 0x00;
	hotbarSlot = 0x00;
	unknown = 0x00;
}

void MobEquipment::decode() {
	++position; // Skip Packet ID
	entityID = getVarULong();
	// ItemStack::deserialize
	inventorySlot = getByte();
	hotbarSlot = getByte();
	unknown = getByte();
}

void MobEquipment::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::MobEquipment));
	putVarULong(entityID);
	// ItemStack::serialize
	putByte(inventorySlot);
	putByte(hotbarSlot);
	putByte(unknown);
}