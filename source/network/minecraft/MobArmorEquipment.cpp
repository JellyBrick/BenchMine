#include "MobArmorEquipment.h"

#include "MinecraftPackets.h"

MobArmorEquipment::MobArmorEquipment() : DataPacket(64) {
	this->entityID = 0;
}

void MobArmorEquipment::decode() {
	++this->position; // Skip Packet ID
	this->entityID = this->getVarULong();
	// ItemStack deserialize
}

void MobArmorEquipment::encode() {
	this->putByte((uint8)MinecraftPackets::MobArmorEquipment);
	this->putVarULong(this->entityID);
	// ItemStack serialize
}