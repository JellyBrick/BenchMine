#include "Level.h"

#include "world/level/chunk/Chunk.h"
#include "world/level/chunk/ChunkSection.h"
#include "world/math/Vector3i.h"

Level::Level(int32 chunkViewDistance) {
	// Generate chunks in view radius
	for (int32 x = -chunkViewDistance; x < chunkViewDistance; ++x) {
		for (int32 z = -chunkViewDistance; z < chunkViewDistance; ++z) {
			chunks[std::make_pair(x, z)] = std::make_unique<Chunk>();
		}
	}

	// Generate an flatland. Until an proper world gen is implemented
	for (int32 x = -chunkViewDistance * 16; x < chunkViewDistance * 16; ++x) {
		for (int32 y = 0; y <= 3; ++y) {
			for (int32 z = -chunkViewDistance * 16; z < chunkViewDistance * 16; ++z) {
				if (y == 0) {
					this->setBlock(0x07, { x, y, z });
				} else if (y < 3) {
					this->setBlock(0x02, { x, y, z });
				} else {
					this->setBlock(0x03, { x, y, z });
				}
			}
		}
	}
}

Chunk* Level::getChunk(int32 x, int32 z) {
	return chunks[std::make_pair(x, z)].get();
}

void Level::setBlock(uint8 blockID, const Vector3i& position) {
	this->getChunk(position.x >> 4, position.z >> 4)->setBlock(blockID, position.x & 0x0F, position.y & 0xFF, position.z & 0x0F);
}

void Level::setBlockAndData(uint8 blockID, uint8 data, const Vector3i& position) {
	this->getChunk(position.x >> 4, position.z >> 4)->setBlockAndData(blockID, data, position.x & 0x0F, position.y & 0xFF, position.z & 0x0F);
}

void Level::setBlockData(uint8 data, const Vector3i& position) {
	this->getChunk(position.x >> 4, position.z >> 4)->setBlockData(data, position.x & 0x0F, position.y & 0xFF, position.z & 0x0F);
}

uint8 Level::getBlock(const Vector3i& position) {
	return this->getChunk(position.x >> 4, position.z >> 4)->getBlock(position.x & 0x0F, position.y & 0xFF, position.z & 0x0F);
}

std::pair<uint8, uint8> Level::getBlockAndData(const Vector3i& position) {
	return this->getChunk(position.x >> 4, position.z >> 4)->getBlockAndData(position.x & 0x0F, position.y & 0xFF, position.z & 0x0F);
}

uint8 Level::getBlockData(const Vector3i& position) {
	return this->getChunk(position.x >> 4, position.z >> 4)->getBlockData(position.x & 0x0F, position.y & 0xFF, position.z & 0x0F);
}