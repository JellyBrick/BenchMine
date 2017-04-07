#include "ResourcePacksInfo.h"

#include "MinecraftPackets.h"

ResourcePacksInfo::ResourcePacksInfo() : DataPacket(512) {
	packsRequired = false;
}

void ResourcePacksInfo::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ResourcePacksInfo));
	putBool(packsRequired);
	putEntries(behaviorPackEntries);
	putEntries(resourcePackEntries);
}

void ResourcePacksInfo::putEntries(const std::vector<PackEntry>& entries) {
	setEndianness(BIG_ENDIAN);
	putUShort(static_cast<uint16>(entries.size()));
	setEndianness(LITTLE_ENDIAN);

	for (const auto& entry : entries) {
		putVarString(entry.packID);
		putVarString(entry.packVersion);
		putULong(entry.packSize);
	}
}