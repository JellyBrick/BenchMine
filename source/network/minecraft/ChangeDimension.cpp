#include "ChangeDimension.h"

#include "MinecraftPackets.h"

ChangeDimension::ChangeDimension() : DataPacket(32) {
	this->dimension = Dimension::Overworld;
	this->unknown = false;
}

void ChangeDimension::encode() {
	this->putByte((uint8)MinecraftPackets::ChangeDimension);
	this->putVarUInt((uint32)this->dimension);
	Vector3f::serialize(this->spawnPosition, *this);
	this->putBool(this->unknown);
}