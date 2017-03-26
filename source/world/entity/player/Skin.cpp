#include "Skin.h"


Skin::Skin() : length(0), texture(nullptr) {}

Skin::Skin(const std::string& skinType, uint8* textureBuffer, uint32 size) 
	: type(std::move(skinType)), length(size), texture(textureBuffer) {}

Skin::~Skin() {
	if (texture != nullptr) {
		delete[] texture;
		length = 0;
	}
}


const std::string& Skin::getType() const {
	return this->type;
}

uint32 Skin::getLength() const {
	return this->length;
}

uint8* Skin::getTexture() const {
	return this->texture;
}

std::unique_ptr<Skin> Skin::fromByteBuffer(RakLib::ByteBuffer& byteBuffer) {
	std::string skinType = byteBuffer.getString();
	if (skinType.empty()) {
		return nullptr;
	}

	uint32 textureLength = byteBuffer.getUInt();
	if (textureLength < 1) {
		return std::make_unique<Skin>(skinType, nullptr, 0);
	}

	uint8* textureBuffer = byteBuffer.getByte(textureLength);
	return std::make_unique<Skin>(skinType, textureBuffer, textureLength);
}




