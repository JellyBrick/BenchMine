#include "Respawn.h"

#include "MinecraftPackets.h"

Respawn::Respawn() : DataPacket(16) {
	setEndianness(Endianness::LITTLE);
}

void Respawn::decode() {
	++position; // Skip Packet ID
	spawnPosition = Vector3f::deserialize(*this);
}

void Respawn::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::Respawn));
	Vector3f::serialize(spawnPosition, *this);
}