#pragma once

#include <array>
#include <memory>
#include <utility>

#include <Common.h>

class ChunkSection;

class Chunk {
private:
	std::array<std::unique_ptr<ChunkSection>, 16> sections;

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
	inline ChunkSection* getChunkSection(uint8 index);

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
	* Get block id at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	* @return uint8 blockID
	*/
	uint8 getBlock(uint8 x, uint8 y, uint8 z);

	/*
	* Get block and data at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	* @return std::pair<blockID, blockData> block id and data
	*/
	std::pair<uint8, uint8> getBlockAndData(uint8 x, uint8 y, uint8 z);

	/*
	* Get block data at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	* @return uint8 block data
	*/
	uint8 getBlockData(uint8 x, uint8 y, uint8 z);

	/*
	* Get emitted light by block at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	* @return uint8 lightLevel
	*/
	uint8 getBlockLight(uint8 x, uint8 y, uint8 z);

	/*
	* Get received light from sky at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 256
	* @param z need to be 0 - 15
	* @return uint8 lightLevel
	*/
	uint8 getSkyLight(uint8 x, uint8 y, uint8 z);
};