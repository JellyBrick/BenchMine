#include "MoveEntity.h"

#include "MinecraftPackets.h"

MoveEntity::MoveEntity() : DataPacket(16) {
	this->entityID = 0;
	this->pitch = 0.0f;
	this->yaw = 0.0f;
	this->headYaw = 0.0f;
}

void MoveEntity::decode() {
	++this->position; // Skip Packet ID
	this->entityID = this->getVarULong();
	this->entityPosition = Vector3f::deserialize(*this);
	this->pitch = f32(this->getByte() * (360.0f / 256.0f));
	this->yaw = f32(this->getByte() * (360.0f / 256.0f));
	this->headYaw = f32(this->getByte() * (360.0f / 256.0f));
}

void MoveEntity::encode() {
	this->putByte((uint8)MinecraftPackets::MoveEntity);
	this->putVarULong(this->entityID);
	Vector3f::serialize(this->entityPosition, *this);
	this->putByte(uint8(this->pitch / (360.0f / 256.0f)));
	this->putByte(uint8(this->yaw / (360.0f / 256.0f)));
	this->putByte(uint8(this->headYaw / (360.0f / 256.0f)));
}
