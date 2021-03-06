#pragma once

#include <string>
#include <vector>

#include <RakLib/protocol/DataPacket.h>

class ResourcePackClientResponse : public RakLib::DataPacket {
public:
	enum Status {
		Refused = 1,
		SendPacks = 2,
		HaveAllPacks = 3,
		Completed = 4
	};

	Status status;
	std::vector<std::string> packs;

public:
	ResourcePackClientResponse(std::unique_ptr<RakLib::Packet>&& packet);

	void decode() override;

	void encode() override;
};