#include "RequestChunkData.h"

RequestChunkData::RequestChunkData(std::unique_ptr<RakLib::Packet>&& packet) : DataPacket(std::move(packet)) {
	radius = 0;
}

void RequestChunkData::decode() {
	getByte(); // Skip Packet ID
	radius = static_cast<int32>(getVarUInt());
}