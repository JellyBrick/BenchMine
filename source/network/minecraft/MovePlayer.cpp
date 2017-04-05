#include "MovePlayer.h"

#include "MinecraftPackets.h"

MovePlayer::MovePlayer() : DataPacket(64) {
	this->entityID = 0;
	this->pitch = 0.0f;
	this->yaw = 0.0f;
	this->bodyYaw = 0.0f;
	this->mode = Mode::NORMAL;
	this->onGround = true;
}

void MovePlayer::decode() {
	++this->position; // Skip Packet ID
	this->entityID = this->getVarULong();
	this->entityPosition = Vector3f::deserialize(*this);
	this->pitch = this->getFloat();
	this->yaw = this->getFloat();
	this->bodyYaw = this->getFloat();
	this->mode = (Mode)this->getByte();
	this->onGround = this->getBool();
}

void MovePlayer::encode() {
	this->putByte((uint8)MinecraftPackets::MovePlayer);
	this->putVarULong(this->entityID);
	Vector3f::serialize(this->entityPosition, *this);
	this->putFloat(this->pitch);
	this->putFloat(this->yaw);
	this->putFloat(this->bodyYaw);
	this->putByte((uint8)this->mode);
	this->putBool(this->onGround);
}
