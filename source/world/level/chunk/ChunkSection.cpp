#include "ChunkSection.h"

ChunkSection::ChunkSection() {
	for (uint32 i = 0; i < blocks.size(); ++i) {
		blocks[i] = 0x00;
	}

	for (uint32 i = 0; i < blockData.size(); ++i) {
		blockData[i] = blockLight[i] = 0x00;
		skyLight[i] = 0xFF;
	}
}

void ChunkSection::setBlock(uint8 blockID, uint8 x, uint8 y, uint8 z) {
	blocks[getRealPosition(x, y, z)] = blockID;
}

void ChunkSection::setBlockAndData(uint8 blockID, uint8 data, uint8 x, uint8 y, uint8 z) {
	uint32 index = getRealPosition(x, y, z);
	blocks[index] = blockID;

	setNibble(blockData[index / 2], data, index % 2 == 0);
}

void ChunkSection::setBlockData(uint8 data, uint8 x, uint8 y, uint8 z) {
	uint32 index = getRealPosition(x, y, z) / 2;
	setNibble(blockData[index], data, index % 2 == 0);
}

void ChunkSection::setBlockLight(uint8 lightLevel, uint8 x, uint8 y, uint8 z) {
	uint32 index = getRealPosition(x, y, z) / 2;
	lightLevel &= 0x0F;
	setNibble(blockLight[index], lightLevel, index % 2 == 0);
}

void ChunkSection::setSkyLight(uint8 skyLightLevel, uint8 x, uint8 y, uint8 z) {
	uint32 index = getRealPosition(x, y, z) / 2;
	setNibble(skyLight[index], skyLightLevel, index % 2 == 0);
}

uint8 ChunkSection::getBlock(uint8 x, uint8 y, uint8 z) const {
	return blocks[getRealPosition(x, y, z)];
}

std::pair<uint8, uint8> ChunkSection::getBlockAndData(uint8 x, uint8 y, uint8 z) const {
	uint32 index = getRealPosition(x, y, z);
	uint8 blockID = blocks[index];
	uint8 data = getNibble(blockData[index / 2], index % 2 == 0);
	return std::make_pair(blockID, data);
}

uint8 ChunkSection::getBlockData(uint8 x, uint8 y, uint8 z) const {
	uint32 index = getRealPosition(x, y, z) / 2;
	return getNibble(blockData[index], index % 2 == 0);
}

uint8 ChunkSection::getBlockLight(uint8 x, uint8 y, uint8 z) const {
	uint32 index = getRealPosition(x, y, z) / 2;
	return getNibble(blockLight[index], index % 2 == 0);
}

uint8 ChunkSection::getSkyLight(uint8 x, uint8 y, uint8 z) const {
	uint32 index = getRealPosition(x, y, z) / 2;
	return getNibble(skyLight[index], index % 2 == 0);
}

uint8* ChunkSection::getBlockArray() const {
	return (uint8*)blocks.data();
}

uint8* ChunkSection::getBlockDataArray() const {
	return (uint8*)blockData.data();
}

uint8* ChunkSection::getBlockLightArray() const {
	return (uint8*)blockLight.data();
}

uint8* ChunkSection::getSkyLightArray() const {
	return (uint8*)skyLight.data();
}

uint32 ChunkSection::getRealPosition(uint8 x, uint8 y, uint8 z) const {
	return x * MAXIMUM_BLOCKS_PER_ROW * MAXIMUM_BLOCKS_PER_ROW + z * MAXIMUM_BLOCKS_PER_ROW + y;
}

void ChunkSection::setNibble(uint8& storage, uint8 nibble, bool leastSignificantBit) const {
	nibble &= 0x0F;
	if (leastSignificantBit) {
		storage = (storage & 0xF0) | nibble;
	} else {
		storage = (storage & 0x0F) | (nibble << 4);
	}
}

uint8 ChunkSection::getNibble(uint8 storage, bool leastSignificantBit) const {
	return leastSignificantBit ? storage & 0x0F : (storage >> 4) & 0x0F;
}