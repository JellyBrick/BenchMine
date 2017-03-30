#pragma once

#include <memory>

#include <zlib.h>

#include "network/ByteBuffer.h"

class Compression {
public:
	static std::unique_ptr<RakLib::ByteBuffer> compress(const RakLib::ByteBuffer& byteBuffer, uint32 compressionLevel = 9);

	static uint32 compress(uint8* input, uint32 inputSize, uint8* output, uint32 outputSize, uint32 compressionLevel = 9);

	static std::unique_ptr<RakLib::ByteBuffer> decompress(const RakLib::ByteBuffer& byteBuffer);

	static uint32 decompress(uint8* input, uint32 inputSize, uint8* output, uint32 outputSize);

};
