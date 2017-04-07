#include "MoveEntity.h"

#include "MinecraftPackets.h"

MoveEntity::MoveEntity() : DataPacket(16) {
	entityID = 0;
	pitch = 0.0f;
	yaw = 0.0f;
	headYaw = 0.0f;
}

void MoveEntity::decode() {
	++position; // Skip Packet ID
	entityID = getVarULong();
	entityPosition = Vector3f::deserialize(*this);
	pitch = f32(getByte() * (360.0f / 256.0f));
	yaw = f32(getByte() * (360.0f / 256.0f));
	headYaw = f32(getByte() * (360.0f / 256.0f));
}

void MoveEntity::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::MoveEntity));
	putVarULong(entityID);
	Vector3f::serialize(entityPosition, *this);
	putByte(uint8(pitch / (360.0f / 256.0f)));
	putByte(uint8(yaw / (360.0f / 256.0f)));
	putByte(uint8(headYaw / (360.0f / 256.0f)));
}
