#include "AddPlayer.h"

#include "MinecraftPackets.h"

AddPlayer::AddPlayer() : DataPacket(64) {
	this->entityID = 0;
	this->pitch = 0.0f;
	this->headYaw = 0.0f;
	this->yaw = 0.0f;
}

void AddPlayer::encode() {
	this->putByte((uint8)MinecraftPackets::AddPlayer);
	this->putByte((uint8*)this->UUID.c_str(), 16); // TODO: Do an proper UUID class
	this->putVarString(this->username);
	this->putVarULong(this->entityID);
	this->putVarULong(this->entityID); // RuntimeEntityID
	Vector3f::serialize(this->entityPosition, *this);
	Vector3f::serialize(this->entityMotion, *this);
	this->putFloat(this->pitch);
	this->putFloat(this->headYaw);
	this->putFloat(this->yaw);
	// ItemStack::serialize
	// EntityMetadata::serialize
}