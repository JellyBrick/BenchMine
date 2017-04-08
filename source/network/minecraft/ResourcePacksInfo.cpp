#include "ResourcePacksInfo.h"

#include "MinecraftPackets.h"

ResourcePacksInfo::ResourcePacksInfo() 
	: DataPacket(128), packsRequired(false) {
	setEndianness(Endianness::LITTLE);
}

void ResourcePacksInfo::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ResourcePacksInfo));
	putBool(packsRequired);
	putEntries(behaviorPackEntries);
	putEntries(resourcePackEntries);
}

void ResourcePacksInfo::putEntries(const std::vector<PackEntry>& entries) {
	putUShort(static_cast<uint16>(entries.size()));
	for (const auto& entry : entries) {
		putVarString(entry.packID);
		putVarString(entry.packVersion);
		putULong(entry.packSize);
	}
}