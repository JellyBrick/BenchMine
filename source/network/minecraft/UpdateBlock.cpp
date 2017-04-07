#include "UpdateBlock.h"

#include "MinecraftPackets.h"

UpdateBlock::UpdateBlock() : DataPacket(32) {
	blockID = 0x00;
	blockData = 0x00;
	flags = FLAG_ALL;
}

void UpdateBlock::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::UpdateBlock));
	Vector3i::serialize(blockPosition, *this);
	putByte(blockID);
	putByte((flags << 4) | blockData);
}