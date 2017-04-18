#include "Batch.h"

#include <cassert>

#include <RakLib/network/ByteBuffer.h>

#include "common/Compression.h"
#include "MinecraftPackets.h"

const uint32 Batch::DEFAULT_BUFFER_SIZE = RakLib::Packet::DEFAULT_BUFFER_SIZE * 2;

Batch::Batch(std::unique_ptr<Packet>&& packet) : RakLib::DataPacket(std::move(packet)) {}

Batch::Batch() : RakLib::DataPacket(DEFAULT_BUFFER_SIZE) {}

Batch::~Batch() {
	packets.clear();
}

void Batch::decode() {
	++position; // Skip Packet ID

	uint32 payloadSize = getVarUInt();
	uint8* payload = buffer + position;
	assert(payloadSize > 1);

	uint8* output = new uint8[DEFAULT_BUFFER_SIZE];
	uint32 outputSize = Compression::decompress(payload, payloadSize, output, DEFAULT_BUFFER_SIZE);
	assert(outputSize != 0);

	RakLib::ByteBuffer byteBuffer(output, outputSize);
	while (byteBuffer.getPosition() < byteBuffer.getLength()) {
		uint32 packetSize = byteBuffer.getVarUInt();
		uint8* packetBuffer = byteBuffer.getByte(packetSize);
		if (packetBuffer != nullptr) {
			packets.push_back(std::make_unique<RakLib::Packet>(packetBuffer, packetSize));
		}
	}

	delete[] output;
}

void Batch::encode() {
	for(const auto& packet : packets) {
		putVarUInt(packet->getLength());
		putByte(packet->getBuffer(), packet->getLength());
	}

	uint8* output = new uint8[DEFAULT_BUFFER_SIZE];
	uint32 outputSize = Compression::compress(buffer, position, output, DEFAULT_BUFFER_SIZE);
	assert(outputSize != 0);

	position = 0;
	putByte(static_cast<uint8>(MinecraftPackets::Batch));
	putVarUInt(outputSize);
	putByte(output, outputSize);
	resize(position);

	// Free Resource
	delete[] output;
	packets.clear();
}