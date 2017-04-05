#include "RemoveBlock.h"

RemoveBlock::RemoveBlock() : DataPacket(16) {}

void RemoveBlock::decode() {
	++this->position; // Skip Packet ID
	this->blockPosition = Vector3i::deserialize(*this);
}
