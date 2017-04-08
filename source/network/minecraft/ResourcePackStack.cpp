#include "ResourcePackStack.h"

#include "MinecraftPackets.h"

ResourcePackStack::ResourcePackStack() : DataPacket(128) {
	packsRequired = false;
	setEndianness(Endianness::LITTLE);
}

void ResourcePackStack::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ResourcePackStack));
	putBool(packsRequired);
	putEntries(behaviorPackEntries);
	putEntries(resourcePackEntries);
}

void ResourcePackStack::putEntries(const std::vector<PackEntry>& entries) {
	putUShort(static_cast<uint16>(entries.size()));
	for (const auto& entry : entries) {
		putVarString(entry.packID);
		putVarString(entry.packVersion);
	}
}