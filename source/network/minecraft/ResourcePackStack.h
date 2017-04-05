#pragma once

#include <vector>

#include <packets/DataPacket.h>

class ResourcePackStack : public RakLib::DataPacket {
public:
	struct PackEntry {
		std::string packID;
		std::string packVersion;
	};

	bool packsRequired;
	std::vector<PackEntry> behaviorPackEntries;
	std::vector<PackEntry> resourcePackEntries;

public:
	ResourcePackStack();

	void encode() override;

private:
	void putEntries(const std::vector<PackEntry>& entries);
};