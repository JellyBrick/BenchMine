#include "Disconnect.h"

#include "MinecraftPackets.h"

Disconnect::Disconnect(const std::string& message) : RakLib::DataPacket(4 + message.length()),
	messageHided(message.empty()), message(message) {}

void Disconnect::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::Disconnect));
	putBool(messageHided);
	putVarString(message);
}