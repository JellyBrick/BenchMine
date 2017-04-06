#include "ResourcePackClientResponse.h"

#include "MinecraftPackets.h"

ResourcePackClientResponse::ResourcePackClientResponse(std::unique_ptr<RakLib::Packet>&& packet) : DataPacket(std::move(packet)) {
	this->status = Status::Completed;
}

void ResourcePackClientResponse::decode() {
	++this->position; // Skip Packet ID
	this->status = (Status)this->getByte();
	
	uint32 entriesCount = this->getUShort() + 1;
	while (--entriesCount > 0) {
		this->packs.push_back(this->getVarString());
	}
}

void ResourcePackClientResponse::encode() {
	this->putByte((uint8)MinecraftPackets::ResourcePackClientResponse);
	this->putByte((uint8)this->status);

	this->putUShort((uint16)this->packs.size());
	for (const auto& packID : this->packs) {
		this->putVarString(packID);
	}
}
