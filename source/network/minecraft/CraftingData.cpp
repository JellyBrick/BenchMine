#include "CraftingData.h"

#include "MinecraftPackets.h"

// TODO: Implement properly when an proper inventory system is implemented
CraftingData::CraftingData() : DataPacket(512) {}

void CraftingData::decode() {
	++position; // Skip Packet ID
}

void CraftingData::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::CraftingData));
}