#pragma once

#include <array>
#include <memory>
#include <utility>

#include <RakLib/Common.h>

#include "ChunkSection.h"

class Chunk {
private:
	static constexpr int SECTIONS_PER_CHUNK = 16;
	static constexpr int BIOME_ID_ARRAY = 256;
	static constexpr int HEIGHTMAP_SIZE = 256;

	std::array<std::unique_ptr<ChunkSection>, SECTIONS_PER_CHUNK> sections;
	std::array<uint8, BIOME_ID_ARRAY> biomeID;
	std::array<uint32, HEIGHTMAP_SIZE> heightMap;

public:
	/*
	 * Create an empty chunk
	 */
	Chunk();

	/*
	 * Get section at index
	 * @param index of the section
	 * @return ChunkSection requested
	 */
	inline ChunkSection* getChunkSection(uint8 index) const;

	/*
	 * Set block at desired position
	 * @param block to be set
	 * @param x need to be 0 - 15
	 * @param y need to be 0 - 256
	 * @param z need to be 0 - 15
	 */
	void setBlock(uint8 block, uint8 x, uint8 y, uint8 z);

	/*
	* Set block and data at desired position
	* @param block to be set
	* @param data to be set
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	*/
	void setBlockAndData(uint8 block, uint8 data, uint8 x, uint8 y, uint8 z);

	/*
	* Set block's data at desired position
	* @param data to be set
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	*/
	void setBlockData(uint8 data, uint8 x, uint8 y, uint8 z);

	/*
	* Set emited light by block at desired position
	* @param blockLight to be set
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	*/
	void setBlockLight(uint8 blockLight, uint8 x, uint8 y, uint8 z);

	/*
	* Set light recived by sky at desired position
	* @param skyLight to be set
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	*/
	void setSkyLight(uint8 skyLight, uint8 x, uint8 y, uint8 z);

	/*
	* Set biomeID at desired position
	* @param newBiomeID to be set
	* @param x need to be 0 - 15
	* @param z need to be 0 - 15
	*/
	void setBiomeID(uint8 newBiomeID, uint8 x, uint8 z);

	/*
	* Set lowest level in each column where the light from the sky is at full strength
	* @param lightValue to be set
	* @param x need to be 0 - 15
	* @param z need to be 0 - 15
	*/
	void setHeightMap(uint32 lightValue, uint8 x, uint8 z);

	/*
	* Get block id at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	* @return uint8 blockID
	*/
	uint8 getBlock(uint8 x, uint8 y, uint8 z) const;

	/*
	* Get block and data at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	* @return std::pair<blockID, blockData> block id and data
	*/
	std::pair<uint8, uint8> getBlockAndData(uint8 x, uint8 y, uint8 z) const;

	/*
	* Get block data at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	* @return uint8 block data
	*/
	uint8 getBlockData(uint8 x, uint8 y, uint8 z) const;

	/*
	* Get emitted light by block at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	* @return uint8 lightLevel
	*/
	uint8 getBlockLight(uint8 x, uint8 y, uint8 z) const;

	/*
	* Get received light from sky at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	* @return uint8 lightLevel
	*/
	uint8 getSkyLight(uint8 x, uint8 y, uint8 z) const;

	/*
	* Get biome id at desired position
	* @param x need to be 0 - 15
	* @param z need to be 0 - 15
	* @return uint8 biomeID
	*/
	uint8 getBiomeID(uint8 x, uint8 z) const;

	/*
	* Get heightMap at desired position
	* @param x need to be 0 - 15
	* @param z need to be 0 - 15
	* @return uint32 heightMap
	*/
	uint32 getHeightMap(uint8 x, uint8 z) const;

	std::pair<uint8*, uint32> serialize();
};