#include "AddPlayer.h"

#include "MinecraftPackets.h"

AddPlayer::AddPlayer() : DataPacket(64) {
	entityID = 0;
	pitch = 0.0f;
	headYaw = 0.0f;
	yaw = 0.0f;
}

void AddPlayer::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::AddPlayer));
	putByte(reinterpret_cast<uint8*>(&UUID[0]), 16); // TODO: Do an proper UUID class
	putVarString(username);
	putVarULong(entityID);
	putVarULong(entityID); // RuntimeEntityID
	Vector3f::serialize(entityPosition, *this);
	Vector3f::serialize(entityMotion, *this);
	putFloat(pitch);
	putFloat(headYaw);
	putFloat(yaw);
	// ItemStack::serialize
	// EntityMetadata::serialize
}