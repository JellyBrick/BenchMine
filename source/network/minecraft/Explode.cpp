#include "Explode.h"

#include "MinecraftPackets.h"

Explode::Explode() : DataPacket(128) {
	this->radius = 0.0f;
}

void Explode::encode() {
	this->putByte((uint8)MinecraftPackets::Explode);
	Vector3f::serialize(this->explosionPosition, *this);
	this->putFloat(this->radius);

	this->putVarUInt((uint32)this->records.size());
	for (const auto& record : this->records) {
		Vector3i::serialize(record, *this);
	}
}