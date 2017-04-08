#include "Text.h"

#include "MinecraftPackets.h"

Text::Text() : DataPacket(64) {
	type = Type::CHAT;
}

void Text::decode() {
	++this->position; // Skip Packet ID

	type = (Type)getByte();
	switch (type) {
	case POPUP:
	case CHAT:
	case WHISPER:
		source = getVarString();
	case RAW:
	case TIP:
	case SYSTEM:
		message = getVarString();
	break;

	case TRANSLATION:
		message = getString();
		auto count = getVarUInt();
		for (uint32 i = 0; i < count; ++i) {
			parameters.push_back(getVarString());
		}

	break;
	}
}

void Text::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::Text));
	putByte(static_cast<uint8>(type));

	switch (type) {
	case POPUP:
	case CHAT:
	case WHISPER:
		putString(source);
	case RAW:
	case TIP:
	case SYSTEM:
		putString(message);
	break;

	case TRANSLATION:
		putString(message);
		putVarUInt(static_cast<uint32>(parameters.size()));
		for (const auto& parameter : parameters) {
			putVarString(parameter);
		}
	break;
	}
}