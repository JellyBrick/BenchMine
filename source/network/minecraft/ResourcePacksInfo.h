#pragma once

#include <packets/DataPacket.h>

#include <vector>

class ResourcePacksInfo : public RakLib::DataPacket {
public:
	struct PackEntry {
		std::string packID;
		std::string packVersion;
		uint64 packSize;
	};

	bool packsRequired;
	std::vector<PackEntry> behaviorPackEntries;
	std::vector<PackEntry> resourcePackEntries;
	
public:
	ResourcePacksInfo();

	void encode() override;

private:
	void putEntries(const std::vector<PackEntry>& entries);
};