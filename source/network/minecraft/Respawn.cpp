#include "Respawn.h"

#include "MinecraftPackets.h"

Respawn::Respawn() : DataPacket(16) {
	this->setEndianness(LITTLE_ENDIAN);
}

void Respawn::decode() {
	++this->position; // Skip Packet ID
	this->spawnPosition = Vector3f::deserialize(*this);
}

void Respawn::encode() {
	this->putByte((uint8)MinecraftPackets::Respawn);
	Vector3f::serialize(this->spawnPosition, *this);
}