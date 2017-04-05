#include "ContainerSetSlot.h"

#include "MinecraftPackets.h"

// TODO: Finish implementation, when an proper inventory system is implemented 
ContainerSetSlot::ContainerSetSlot() : DataPacket(32) {
	this->windowsID = 0x00;
	this->slot = 0;
	this->hotbarSlot = 0;
	this->selectedSlot = 0x00;
}

void ContainerSetSlot::decode() {
	++this->position; // Skip Packet ID
	this->windowsID = this->getByte();
	this->slot = this->getVarUInt();
	this->hotbarSlot = this->getVarUInt();
	// ItemStack::deserialize
	this->selectedSlot = this->getByte();
}

void ContainerSetSlot::encode() {
	this->putByte((uint8)MinecraftPackets::ContainerSetSlot);
	this->putByte(this->windowsID);
	this->putVarUInt(this->slot);
	this->putVarUInt(this->hotbarSlot);
	// ItemStack::serialize
	this->putByte(this->selectedSlot);
}