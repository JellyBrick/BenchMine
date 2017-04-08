#include "MovePlayer.h"

#include "MinecraftPackets.h"

MovePlayer::MovePlayer() : DataPacket(64) {
	entityID = 0;
	pitch = 0.0f;
	yaw = 0.0f;
	bodyYaw = 0.0f;
	mode = Mode::NORMAL;
	onGround = true;
}

void MovePlayer::decode() {
	++position; // Skip Packet ID
	entityID = getVarULong();
	entityPosition = Vector3f::deserialize(*this);
	pitch = getFloat();
	yaw = getFloat();
	bodyYaw = getFloat();
	mode = (Mode)getByte();
	onGround = getBool();
}

void MovePlayer::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::MovePlayer));
	putVarULong(entityID);
	Vector3f::serialize(entityPosition, *this);
	putFloat(pitch);
	putFloat(yaw);
	putFloat(bodyYaw);
	putByte(static_cast<uint8>(mode));
	putBool(onGround);
}