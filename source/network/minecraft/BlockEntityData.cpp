#include "BlockEntityData.h"

#include "MinecraftPackets.h"

BlockEntityData::BlockEntityData() : DataPacket(128) {}

void BlockEntityData::decode() {
	++this->position; // Skip Packet ID
	Vector3i::deserialize(*this);
	//TODO: Deserialize NBT CompoundTag
}

void BlockEntityData::encode() {
	this->putByte((uint8)MinecraftPackets::BlockEntityData);
	Vector3i::serialize(this->blockPosition, *this);
	//TODO: Serialize NBT CompoundTag
}