#include "RequestChunkData.h"

RequestChunkData::RequestChunkData(std::unique_ptr<RakLib::Packet>&& packet) : DataPacket(std::move(packet)) {
	radius = 0;
}

void RequestChunkData::decode() {
	print();
	this->getByte(); // Skip Packet ID
	radius = (int32)this->getVarUInt();
}
