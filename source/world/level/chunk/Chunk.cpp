#include "Chunk.h"

#include <network/ByteBuffer.h>

#include "ChunkSection.h"

Chunk::Chunk() {
	// TODO: Proper Chunk Section population
	this->sections[0] = std::make_unique<ChunkSection>();

	uint32 preCalcLight = SECTIONS_PER_CHUNK * 16 - 1;
	for (uint32 i = 0; i < HEIGHTMAP_SIZE; ++i) {
		this->heightMap[i] = preCalcLight;
		this->biomeID[i] = 0x00;
	}
}

ChunkSection* Chunk::getChunkSection(uint8 index) const {
	return this->sections[index].get();
}

void Chunk::setBlock(uint8 block, uint8 x, uint8 y, uint8 z) {
	this->sections[y >> 4]->setBlock(block, x, y & 0x0F, z);
}

void Chunk::setBlockAndData(uint8 block, uint8 data, uint8 x, uint8 y, uint8 z) {
	this->sections[y >> 4]->setBlockAndData(block, data, x, y & 0x0F, z);
}

void Chunk::setBlockData(uint8 data, uint8 x, uint8 y, uint8 z) {
	this->sections[y >> 4]->setBlockData(data, x, y & 0x0F, z);
}

void Chunk::setBlockLight(uint8 blockLight, uint8 x, uint8 y, uint8 z){
	this->sections[y >> 4]->setBlockLight(blockLight, x, y & 0x0F, z);
}

void Chunk::setSkyLight(uint8 skyLight, uint8 x, uint8 y, uint8 z){
	this->sections[y >> 4]->setSkyLight(skyLight, x, y & 0x0F, z);
}

void Chunk::setBiomeID(uint8 newBiomeID, uint8 x, uint8 z) {
	this->biomeID[(z << 4) | x] = newBiomeID;
}

void Chunk::setHeightMap(uint32 lightValue, uint8 x, uint8 z) {
	this->heightMap[(z << 4) | x] = lightValue;
}

uint8 Chunk::getBlock(uint8 x, uint8 y, uint8 z) const {
	return this->sections[y >> 4]->getBlock(x, y & 0xF, z);
}

std::pair<uint8, uint8> Chunk::getBlockAndData(uint8 x, uint8 y, uint8 z) const {
	return this->sections[y >> 4]->getBlockAndData(x, y & 0x0F, z);
}

uint8 Chunk::getBlockData(uint8 x, uint8 y, uint8 z) const {
	return this->sections[y >> 4]->getBlockData(x, y & 0x0F, z);
}

uint8 Chunk::getBlockLight(uint8 x, uint8 y, uint8 z) const {
	return this->sections[y >> 4]->getBlockLight(x, y & 0x0F, z);
}

uint8 Chunk::getSkyLight(uint8 x, uint8 y, uint8 z) const {
	return this->sections[y >> 4]->getSkyLight(x, y & 0x0F, z);
}

uint8 Chunk::getBiomeID(uint8 x, uint8 z) const {
	return this->biomeID[(z << 4) | x];
}

uint32 Chunk::getHeightMap(uint8 x, uint8 z) const {
	return this->heightMap[(z << 4) | x];
}

std::pair<uint8*, uint32> Chunk::serialize() {
	uint32 chunkSectionCount = 0;
	for (uint32 i = 0; i < this->sections.size(); ++i) {
		if (this->sections[i]) {
			++chunkSectionCount;
		}
	}

	if (chunkSectionCount == 0) {
		return { nullptr, 0 };
	}

	uint32 chunkBuffeSize = 1 + chunkSectionCount + sizeof(ChunkSection) * chunkSectionCount + sizeof(this->heightMap) + sizeof(this->biomeID) + 2;
	uint8* chunkBuffer = new uint8[chunkBuffeSize];

	RakLib::ByteBuffer byteBuffer(chunkBuffer, chunkBuffeSize);
	byteBuffer.putByte((uint8)chunkSectionCount);

	// Serialize Chunk Section
	for (uint32 i = 0; i < this->sections.size(); ++i) {
		const auto& chunk = this->sections[i];
		if (chunk) {
			byteBuffer.putByte(0x00); // Storage Version
			byteBuffer.putByte(chunk->getBlockArray(), ChunkSection::MAXIMUM_BLOCKS_PER_SECTION);
			byteBuffer.putByte(chunk->getBlockDataArray(), ChunkSection::MAXIMUM_NIBBLE_PER_SECTION);
			byteBuffer.putByte(chunk->getSkyLightArray(), ChunkSection::MAXIMUM_NIBBLE_PER_SECTION);
			byteBuffer.putByte(chunk->getBlockLightArray(), ChunkSection::MAXIMUM_NIBBLE_PER_SECTION);
		}
	}

	byteBuffer.putByte((uint8*)this->heightMap.data(), sizeof(this->heightMap));
	byteBuffer.putByte((uint8*)this->biomeID.data(), sizeof(this->biomeID));
	byteBuffer.putByte(0x00); // block border array count

	byteBuffer.putByte(0x00); // Unknown Count

	return { chunkBuffer, chunkBuffeSize };
}