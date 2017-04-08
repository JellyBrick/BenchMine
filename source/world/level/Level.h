#pragma once

#include <map>
#include <memory>
#include <utility>
#include <vector>

#include <RakLib/Common.h>

#include "world/entity/Entity.h"
#include "world/math/Vector3f.h"
#include "world/level/chunk/Chunk.h"

class Vector3i;

class Level {
private:
	std::map<std::pair<int32, int32>, std::unique_ptr<Chunk>> chunks;
	std::vector<std::unique_ptr<Entity>> entities;

public:
	Level(int32 chunkViewDistance);

	void update();

	void addEntity(std::unique_ptr<Entity>&& entity);

	Entity* getEntity(uint64 entityID);

	Entity* getEntity(Vector3f entityPosition);

	void removeEntity(uint64 entityID);

	void removeEntity(Vector3f entityPosition);

	Chunk* getChunk(int32 x, int32 z);

	void setBlock(uint8 blockID, const Vector3i& position);

	void setBlockAndData(uint8 blockID, uint8 data, const Vector3i& position);

	void setBlockData(uint8 data, const Vector3i& position);

	uint8 getBlock(const Vector3i& position);

	std::pair<uint8, uint8> getBlockAndData(const Vector3i& position);

	uint8 getBlockData(const Vector3i& position);
};