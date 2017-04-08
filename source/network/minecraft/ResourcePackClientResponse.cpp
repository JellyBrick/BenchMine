#include "ResourcePackClientResponse.h"

#include "MinecraftPackets.h"

ResourcePackClientResponse::ResourcePackClientResponse(std::unique_ptr<RakLib::Packet>&& packet) : DataPacket(std::move(packet)) {
	status = Status::Completed;
}

void ResourcePackClientResponse::decode() {
	++position; // Skip Packet ID
	status = (Status)getByte();
	
	uint32 entriesCount = getUShort() + 1;
	while (--entriesCount > 0) {
		packs.push_back(getVarString());
	}
}

void ResourcePackClientResponse::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ResourcePackClientResponse));
	putByte(static_cast<uint8>(status));

	putUShort(static_cast<uint16>(packs.size()));
	for (const auto& packID : packs) {
		putVarString(packID);
	}
}
