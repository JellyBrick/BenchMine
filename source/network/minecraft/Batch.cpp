#include "Batch.h"

#include <cassert>

#include <network/ByteBuffer.h>

#include "common/Compression.h"

Batch::Batch(std::unique_ptr<Packet>&& packet) : RakLib::DataPacket(std::move(packet)) {}

Batch::Batch() : RakLib::DataPacket(Packet::DEFAULT_BUFFER_SIZE) {}

Batch::~Batch() {
	this->packets.clear();
}

void Batch::decode() {
	this->position = 1; // Skip Packet ID

	uint32 payloadSize = this->getVarUInt();
	uint8* payload = this->buffer + this->position;
	assert(payloadSize > 1);

	uint8* output = new uint8[Packet::DEFAULT_BUFFER_SIZE * 8]; // 16 Megabytes
	uint32 outputSize = Compression::decompress(payload, payloadSize, output, Packet::DEFAULT_BUFFER_SIZE * 8);
	assert(outputSize != 0);

	RakLib::ByteBuffer byteBuffer(output, outputSize);
	while (byteBuffer.getPosition() < byteBuffer.getLength()) {
		uint32 packetSize = byteBuffer.getVarUInt();
		uint8* packetBuffer = byteBuffer.getByte(packetSize);
		if (packetBuffer != nullptr) {
			this->packets.push_back(std::make_unique<RakLib::Packet>(packetBuffer, packetSize, "", 0));
		}
	}

	delete[] output;
}

void Batch::encode() {
	
}