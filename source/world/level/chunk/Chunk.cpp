#include "Chunk.h"

#include "ChunkSection.h"

Chunk::Chunk() {
	// TODO
}

const ChunkSection& Chunk::getChunkSection(uint8 index) {
	return this->sections[index];
}

uint8 Chunk::getBlock(uint8 x, uint8 y, uint8 z) {
	return this->sections[y >> 4].getBlock(x, y & 0xF, z);
}

std::pair<uint8, uint8> Chunk::getBlockAndData(uint8 x, uint8 y, uint8 z) {
	return this->sections[y >> 4].getBlockAndData(x, y & 0x0F, z);
}

uint8 Chunk::getBlockData(uint8 x, uint8 y, uint8 z) {
	return this->sections[y >> 4].getBlockData(x, y & 0x0F, z);
}

uint8 Chunk::getBlockLight(uint8 x, uint8 y, uint8 z) {
	return this->sections[y >> 4].getBlockLight(x, y & 0x0F, z);
}

uint8 Chunk::getSkyLight(uint8 x, uint8 y, uint8 z) {
	return this->sections[y >> 4].getSkyLight(x, y & 0x0F, z);
}

void Chunk::setBlock(uint8 block, uint8 x, uint8 y, uint8 z) {
	this->sections[y >> 4].setBlock(block, x, y & 0x0F, z);
}

void Chunk::setBlockAndData(uint8 block, uint8 data, uint8 x, uint8 y, uint8 z) {
	this->sections[y >> 4].setBlockAndData(block, data, x, y & 0x0F, z);
}

void Chunk::setBlockData(uint8 data, uint8 x, uint8 y, uint8 z) {
	this->sections[y >> 4].setBlockData(data, x, y & 0x0F, z);
}

void Chunk::setBlockLight(uint8 blockLight, uint8 x, uint8 y, uint8 z) {
	this->sections[y >> 4].setBlockLight(blockLight, x, y & 0x0F, z);
}

void Chunk::setSkyLight(uint8 skyLight, uint8 x, uint8 y, uint8 z) {
	this->sections[y >> 4].setSkyLight(skyLight, x, y & 0x0F, z);
}
