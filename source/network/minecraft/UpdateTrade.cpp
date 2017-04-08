#include "UpdateTrade.h"

#include "MinecraftPackets.h"

// TODO: Do more research about the fields
UpdateTrade::UpdateTrade() : DataPacket(512) {}

void UpdateTrade::decode() {
	++position; // Skip Packet ID
}

void UpdateTrade::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::UpdateTrade));
}
