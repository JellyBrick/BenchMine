#include "MobEquipment.h"

#include "MinecraftPackets.h"

MobEquipment::MobEquipment() : DataPacket(32) {
	this->entityID = 0;
	this->inventorySlot = 0x00;
	this->hotbarSlot = 0x00;
	this->unknown = 0x00;
}

void MobEquipment::decode() {
	++this->position; // Skip Packet ID
	this->entityID = this->getVarULong();
	// ItemStack::deserialize
	this->inventorySlot = this->getByte();
	this->hotbarSlot = this->getByte();
	this->unknown = this->getByte();
}

void MobEquipment::encode() {
	this->putByte((uint8)MinecraftPackets::MobEquipment);
	this->putVarULong(this->entityID);
	// ItemStack::serialize
	this->putByte(this->inventorySlot);
	this->putByte(this->hotbarSlot);
	this->putByte(this->unknown);
}