#include "Compression.h"

std::unique_ptr<RakLib::ByteBuffer> Compression::compress(const RakLib::ByteBuffer& byteBuffer, uint32 compressionLevel) {
	z_stream stream;
	stream.zalloc = Z_NULL;
	stream.zfree = Z_NULL;
	stream.opaque = Z_NULL;

	stream.avail_in = byteBuffer.getLength();
	stream.next_in = byteBuffer.getBuffer();

	uint8* buffer = new uint8[byteBuffer.getLength()];
	stream.avail_out = byteBuffer.getLength();
	stream.next_out = buffer;

	deflateInit(&stream, compressionLevel);
	deflate(&stream, Z_FINISH);
	deflateEnd(&stream);

	return std::make_unique<RakLib::ByteBuffer>(buffer, stream.total_out);
}

uint32 Compression::compress(uint8* input, uint32 inputSize, uint8* output, uint32 outputSize, uint32 compressionLevel) {
	z_stream stream;
	stream.zalloc = Z_NULL;
	stream.zfree = Z_NULL;
	stream.opaque = Z_NULL;

	stream.avail_in = inputSize;
	stream.next_in = input;

	stream.avail_out = outputSize;
	stream.next_out = output;

	deflateInit(&stream, compressionLevel);
	deflate(&stream, Z_FINISH);
	deflateEnd(&stream);

	return stream.total_out;
}

std::unique_ptr<RakLib::ByteBuffer> Compression::decompress(const RakLib::ByteBuffer& byteBuffer) {
	z_stream stream;
	stream.zalloc = Z_NULL;
	stream.zfree = Z_NULL;
	stream.opaque = Z_NULL;

	stream.avail_in = byteBuffer.getLength();
	stream.next_in = byteBuffer.getBuffer();

	uint8* buffer = new uint8[byteBuffer.getLength()];
	stream.avail_out = byteBuffer.getLength();
	stream.next_out = buffer;

	inflateInit2(&stream, MAX_WBITS | 32);
	inflate(&stream, Z_NO_FLUSH);
	inflateEnd(&stream);

	return std::make_unique<RakLib::ByteBuffer>(buffer, stream.total_out);
}

uint32 Compression::decompress(uint8* input, uint32 inputSize, uint8* output, uint32 outputSize) {
	z_stream stream;
	stream.zalloc = Z_NULL;
	stream.zfree = Z_NULL;
	stream.opaque = Z_NULL;

	stream.avail_in = inputSize;
	stream.next_in = input;

	stream.avail_out = outputSize;
	stream.next_out = output;

	inflateInit2(&stream, MAX_WBITS | 32);
	inflate(&stream, Z_NO_FLUSH);
	inflateEnd(&stream);

	return stream.total_out;
}