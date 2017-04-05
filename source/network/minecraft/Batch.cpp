#include "Batch.h"

#include <cassert>

#include <network/ByteBuffer.h>

#include "common/Compression.h"
#include "MinecraftPackets.h"

Batch::Batch(std::unique_ptr<Packet>&& packet) : RakLib::DataPacket(std::move(packet)) {}

Batch::Batch() : RakLib::DataPacket(DEFAULT_BUFFER_SIZE) {}

Batch::~Batch() {
	this->packets.clear();
}

void Batch::decode() {
	++this->position; // Skip Packet ID

	uint32 payloadSize = this->getVarUInt();
	uint8* payload = this->buffer + this->position;
	assert(payloadSize > 1);

	uint8* output = new uint8[DEFAULT_BUFFER_SIZE];
	uint32 outputSize = Compression::decompress(payload, payloadSize, output, DEFAULT_BUFFER_SIZE);
	assert(outputSize != 0);

	RakLib::ByteBuffer byteBuffer(output, outputSize);
	while (byteBuffer.getPosition() < byteBuffer.getLength()) {
		uint32 packetSize = byteBuffer.getVarUInt();
		uint8* packetBuffer = byteBuffer.getByte(packetSize);
		if (packetBuffer != nullptr) {
			this->packets.push_back(std::make_unique<RakLib::Packet>(packetBuffer, packetSize));
		}
	}

	delete[] output;
}

void Batch::encode() {
	for(const auto& packet : this->packets) {
		this->putVarUInt(packet->getLength());
		this->putByte(packet->getBuffer(), packet->getLength());
	}

	uint8* output = new uint8[DEFAULT_BUFFER_SIZE];
	uint32 outputSize = Compression::compress(this->buffer, this->position, output, DEFAULT_BUFFER_SIZE);
	assert(outputSize != 0);

	this->position = 0;
	this->putByte((uint8)MinecraftPackets::Batch);
	this->putVarUInt(outputSize);
	this->putByte(output, outputSize);
	this->resize(this->position);

	// Free Resource
	delete[] output;
	this->packets.clear();
}