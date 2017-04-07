#include "ResourcePackStack.h"

#include "MinecraftPackets.h"

ResourcePackStack::ResourcePackStack() : DataPacket(128) {
	this->packsRequired = false;
}

void ResourcePackStack::encode() {
	this->putByte((uint8)MinecraftPackets::ResourcePackStack);
	this->putBool(this->packsRequired);
	this->putEntries(this->behaviorPackEntries);
	this->putEntries(this->resourcePackEntries);
}

void ResourcePackStack::putEntries(const std::vector<PackEntry>& entries) {
	this->setEndianness(this->BIG_ENDIAN);
	this->putUShort((uint16)entries.size());
	this->setEndianness(LITTLE_ENDIAN);

	for (const auto& entry : entries) {
		this->putVarString(entry.packID);
		this->putVarString(entry.packVersion);
	}
}