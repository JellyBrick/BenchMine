#include "RemoveBlock.h"

RemoveBlock::RemoveBlock() : DataPacket(16) {}

void RemoveBlock::decode() {
	++position; // Skip Packet ID
	blockPosition = Vector3i::deserialize(*this);
}
