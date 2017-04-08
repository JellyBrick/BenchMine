#include "ChangeDimension.h"

#include "MinecraftPackets.h"

ChangeDimension::ChangeDimension() : DataPacket(32) {
	dimension = Dimension::Overworld;
	unknown = false;
}

void ChangeDimension::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ChangeDimension));
	putVarUInt(static_cast<uint32>(dimension));
	Vector3f::serialize(spawnPosition, *this);
	putBool(unknown);
}