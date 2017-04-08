#include "MobArmorEquipment.h"

#include "MinecraftPackets.h"

MobArmorEquipment::MobArmorEquipment() : DataPacket(64) {
	entityID = 0;
}

void MobArmorEquipment::decode() {
	++position; // Skip Packet ID
	entityID = getVarULong();
	// ItemStack deserialize
}

void MobArmorEquipment::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::MobArmorEquipment));
	putVarULong(entityID);
	// ItemStack serialize
}