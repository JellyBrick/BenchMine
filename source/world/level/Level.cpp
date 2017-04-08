#include "Level.h"

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
				Vector3i position = Vector3i(x, y, z);
				if (y == 0) {
					setBlock(0x07, position);
				} else if (y < 3) {
					setBlock(0x02, position);
				} else {
					setBlock(0x03, position);
				}
			}
		}
	}
}

void Level::update() {
	for (size_t i = 0; i < entities.size(); ++i) {
		const auto& entity = entities[i];
		if (entity && entity->isRemoved()) {
			entity->onRemove();
			entities.erase(entities.begin() + i);
		}
	}
	
	for (const auto& entity : entities) {
		if (entity) {
			entity->update();
		}
	}

	// TODO: Update Chunk
}

void Level::addEntity(std::unique_ptr<Entity>&& entity) {
	entities.push_back(std::move(entity));
}

Entity* Level::getEntity(uint64 entityID) {
	for (const auto& entity : entities) {
		if (entity && entity->getID() == entityID) {
			return entity.get();
		}
	}

	return nullptr;
}

Entity* Level::getEntity(Vector3f entityPosition) {
	for (const auto& entity : entities) {
		if (entity && entity->getPosition() == entityPosition) {
			return entity.get();
		}
	}

	return nullptr;
}

void Level::removeEntity(uint64 entityID) {
	for (size_t i = 0; i < entities.size(); ++i) {
		const auto& entity = entities[i];
		if (entity && entity->getID() == entityID) {
			entity->onRemove();
			entities.erase(entities.begin() + i);
		}
	}
}

void Level::removeEntity(Vector3f entityPosition) {
	for (size_t i = 0; i < entities.size(); ++i) {
		const auto& entity = entities[i];
		if (entity && entity->getPosition() == entityPosition) {
			entity->onRemove();
			entities.erase(entities.begin() + i);
		}
	}
}

Chunk* Level::getChunk(int32 x, int32 z) {
	return chunks[std::make_pair(x, z)].get();
}

void Level::setBlock(uint8 blockID, const Vector3i& position) {
	getChunk(position.x >> 4, position.z >> 4)->setBlock(blockID, position.x & 0x0F, position.y & 0xFF, position.z & 0x0F);
}

void Level::setBlockAndData(uint8 blockID, uint8 data, const Vector3i& position) {
	getChunk(position.x >> 4, position.z >> 4)->setBlockAndData(blockID, data, position.x & 0x0F, position.y & 0xFF, position.z & 0x0F);
}

void Level::setBlockData(uint8 data, const Vector3i& position) {
	getChunk(position.x >> 4, position.z >> 4)->setBlockData(data, position.x & 0x0F, position.y & 0xFF, position.z & 0x0F);
}

uint8 Level::getBlock(const Vector3i& position) {
	return getChunk(position.x >> 4, position.z >> 4)->getBlock(position.x & 0x0F, position.y & 0xFF, position.z & 0x0F);
}

std::pair<uint8, uint8> Level::getBlockAndData(const Vector3i& position) {
	return getChunk(position.x >> 4, position.z >> 4)->getBlockAndData(position.x & 0x0F, position.y & 0xFF, position.z & 0x0F);
}

uint8 Level::getBlockData(const Vector3i& position) {
	return getChunk(position.x >> 4, position.z >> 4)->getBlockData(position.x & 0x0F, position.y & 0xFF, position.z & 0x0F);
}