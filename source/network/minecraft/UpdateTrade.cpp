#include "UpdateTrade.h"

#include "MinecraftPackets.h"

// TODO: Do more research about the fields
UpdateTrade::UpdateTrade() : DataPacket(512) {}

void UpdateTrade::decode() {
	++this->position; // Skip Packet ID
}

void UpdateTrade::encode() {
	this->putByte((uint8)MinecraftPackets::UpdateTrade);
}
