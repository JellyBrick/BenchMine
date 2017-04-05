#include "Text.h"

#include "MinecraftPackets.h"

Text::Text() : DataPacket(64) {
	this->type = Type::CHAT;
}

void Text::decode() {
	this->type = (Type)this->getByte();
	switch (this->type) {
	case POPUP:
	case CHAT:
	case WHISPER:
		this->source = this->getVarString();
	case RAW:
	case TIP:
	case SYSTEM:
		this->message = this->getVarString();
	break;

	case TRANSLATION:
		this->message = this->getString();
		auto count = this->getVarUInt();
		for (auto i = 0; i < count; ++i) {
			this->parameters.push_back(this->getVarString());
		}

	break;
	}
}

void Text::encode() {
	++this->position; // Skip Packet ID
	this->putByte((uint8)MinecraftPackets::Text);
	this->putByte((uint8)this->type);

	switch (this->type) {
	case POPUP:
	case CHAT:
	case WHISPER:
		this->putString(this->source);
	case RAW:
	case TIP:
	case SYSTEM:
		this->putString(this->message);
	break;

	case TRANSLATION:
		this->putString(this->message);
		this->putVarUInt((uint32)this->parameters.size());
		for (const auto& parameter : this->parameters) {
			this->putVarString(parameter);
		}
	break;
	}
}