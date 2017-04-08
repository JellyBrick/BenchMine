#include "Explode.h"

#include "MinecraftPackets.h"

Explode::Explode() : DataPacket(128) {
	radius = 0.0f;
}

void Explode::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::Explode));
	Vector3f::serialize(explosionPosition, *this);
	putFloat(radius);

	putVarUInt(static_cast<uint32>(records.size()));
	for (const auto& record : records) {
		Vector3i::serialize(record, *this);
	}
}