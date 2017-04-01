#pragma once

#include <array>
#include <utility>

#include <Common.h>

class ChunkSection {
public:
	static constexpr uint32 MAXIMUM_BLOCKS_PER_SECTION = 4096;
	static constexpr uint32 MAXIMUM_NIBBLE_PER_SECTION = 4096 / 2;
	static constexpr uint32 MAXIMUM_BLOCKS_PER_ROW = 16;

private:
	std::array<uint8, MAXIMUM_BLOCKS_PER_SECTION> blocks;
	std::array<uint8, MAXIMUM_NIBBLE_PER_SECTION> blockData;
	std::array<uint8, MAXIMUM_NIBBLE_PER_SECTION> blockLight;
	std::array<uint8, MAXIMUM_NIBBLE_PER_SECTION> skyLight;

public:
	/*
	 * Construct an empty chunk section.
	 * NOTE: Would set the entire chunk section sky light to max
	 */
	ChunkSection();

	/*
	 * Set block at desired position
	 * @param blockID to be set
	 * @param x need to be 0 - 15
	 * @param y need to be 0 - 15
	 * @param z need to be 0 - 15
	 */
	void setBlock(uint8 blockID, uint8 x, uint8 y, uint8 z);

	/*
	* Set block and data at desired position
	* @param blockID to be set
	* @param data related to the block
	* @param x need to be 0 - 15
	* @param y need to be 0 - 15
	* @param z need to be 0 - 15
	*/
	void setBlockAndData(uint8 blockID, uint8 data, uint8 x, uint8 y, uint8 z);

	/*
	* Set block data at desired position
	* @param data to be set
	* @param x need to be 0 - 15
	* @param y need to be 0 - 15
	* @param z need to be 0 - 15
	*/
	void setBlockData(uint8 data, uint8 x, uint8 y, uint8 z);

	/*
	* Set light emited by block at desired position
	* @param lightLevel level to be set
	* @param x need to be 0 - 15
	* @param y need to be 0 - 15
	* @param z need to be 0 - 15
	*/
	void setBlockLight(uint8 lightLevel, uint8 x, uint8 y, uint8 z);

	/*
	* Set light level received at desired position
	* @param skyLightLevel to be set
	* @param x need to be 0 - 15
	* @param y need to be 0 - 15
	* @param z need to be 0 - 15
	*/
	void setSkyLight(uint8 skyLightLevel, uint8 x, uint8 y, uint8 z);

	/*
	* Get block id at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 15
	* @param z need to be 0 - 15
	* @return uint8 blockID
	*/
	uint8 getBlock(uint8 x, uint8 y, uint8 z) const;

	/*
	* Get block and data at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 15
	* @param z need to be 0 - 15
	* @return std::pair<blockID, blockData> block id and data
	*/
	std::pair<uint8, uint8> getBlockAndData(uint8 x, uint8 y, uint8 z) const;

	/*
	* Get block data at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 15
	* @param z need to be 0 - 15
	* @return uint8 block data
	*/
	uint8 getBlockData(uint8 x, uint8 y, uint8 z) const;

	/*
	* Get emitted light by block at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 15
	* @param z need to be 0 - 15
	* @return uint8 lightLevel
	*/
	uint8 getBlockLight(uint8 x, uint8 y, uint8 z) const;

	/*
	* Get received light from sky at desired position
	* @param x need to be 0 - 15
	* @param y need to be 0 - 15
	* @param z need to be 0 - 15
	* @return uint8 lightLevel
	*/
	uint8 getSkyLight(uint8 x, uint8 y, uint8 z) const;

	/*
	* Get raw pointer to blocks from this section
	* @return uint8* blockArray
	*/
	uint8* getBlockArray() const;

	/*
	* Get raw pointer to blocks data from this section
	* @return uint8* blockDataArray
	*/
	uint8* getBlockDataArray() const;

	/*
	* Get raw pointer to blocks light from this section
	* @return uint8* blockLightArray
	*/
	uint8* getBlockLightArray() const;

	/*
	* Get raw pointer to skyLight from this section
	* @return uint8* skyLightArray
	*/
	uint8* getSkyLightArray() const;

private:
	inline uint32 getRealPosition(uint8 x, uint8 y, uint8 z) const;

	inline void setNibble(uint8& storage, uint8 nibble, bool leastSignificantBit) const;

	inline uint8 getNibble(uint8 storage, bool leastSignificantBit) const;
};
