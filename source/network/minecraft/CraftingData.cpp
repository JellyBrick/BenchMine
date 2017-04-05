#include "CraftingData.h"

#include "MinecraftPackets.h"

// TODO: Implement properly when an proper inventory system is implemented
CraftingData::CraftingData() : DataPacket(512) {}

void CraftingData::decode() {
	++this->position; // Skip Packet ID
}

void CraftingData::encode() {
	this->putByte((uint8)MinecraftPackets::CraftingData);
}

