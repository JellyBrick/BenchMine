#pragma once

#include <memory>
#include <string>

#include <RakLib/Common.h>
#include <RakLib/network/ByteBuffer.h>

class Skin final {
private:
	std::string type;
	uint32 length;
	uint8* texture;

private:
	Skin();

public:
	Skin(const std::string& type, uint8* textureBuffer, uint32 size);
	~Skin();

	const std::string& getType() const;

	uint32 getLength() const;

	uint8* getTexture() const;

	static std::unique_ptr<Skin> fromByteBuffer(RakLib::ByteBuffer& byteBuffer);
};