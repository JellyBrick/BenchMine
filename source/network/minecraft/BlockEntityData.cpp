#include "BlockEntityData.h"

#include "MinecraftPackets.h"

BlockEntityData::BlockEntityData() : DataPacket(128) {}

void BlockEntityData::decode() {
	++position; // Skip Packet ID
	Vector3i::deserialize(*this);
	//TODO: Deserialize NBT CompoundTag
}

void BlockEntityData::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::BlockEntityData));
	Vector3i::serialize(blockPosition, *this);
	//TODO: Serialize NBT CompoundTag
}