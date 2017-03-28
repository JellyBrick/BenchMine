#pragma once

#include <map>
#include <memory>
#include <utility>

#include <Common.h>

class Chunk;
class Vector3i;

class Level {
private:
	std::map<std::pair<int32, int32>, std::unique_ptr<Chunk>> chunks;

public:
	Level(int32 chunkViewDistance);

	Chunk* getChunk(int32 x, int32 z);

	void setBlock(uint8 blockID, const Vector3i& position);

	void setBlockAndData(uint8 blockID, uint8 data, const Vector3i& position);

	void setBlockData(uint8 data, const Vector3i& position);

	uint8 getBlock(const Vector3i& position);

	std::pair<uint8, uint8> getBlockAndData(const Vector3i& position);

	uint8 getBlockData(const Vector3i& position);
};