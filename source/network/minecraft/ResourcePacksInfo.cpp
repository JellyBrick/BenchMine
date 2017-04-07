#include "ResourcePacksInfo.h"

#include "MinecraftPackets.h"

ResourcePacksInfo::ResourcePacksInfo() : DataPacket(512) {
	this->packsRequired = false;
}

void ResourcePacksInfo::encode() {
	this->putByte((uint8)MinecraftPackets::ResourcePacksInfo);
	this->putBool(this->packsRequired);
	this->putEntries(this->behaviorPackEntries);
	this->putEntries(this->resourcePackEntries);
}

void ResourcePacksInfo::putEntries(const std::vector<PackEntry>& entries) {
	this->setEndianness(BIG_ENDIAN);
	this->putUShort((uint16)entries.size());
	this->setEndianness(LITTLE_ENDIAN);

	for (const auto& entry : entries) {
		this->putVarString(entry.packID);
		this->putVarString(entry.packVersion);
		this->putULong(entry.packSize);
	}
}