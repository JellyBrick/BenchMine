#include "Disconnect.h"

#include "MinecraftPackets.h"

Disconnect::Disconnect(const std::string& message) : RakLib::DataPacket(4 + message.length()),
	messageHided(message.empty()), message(message) {}

void Disconnect::encode() {
	this->putByte((uint8)MinecraftPackets::DISCONNECT);
	this->putBool(messageHided);
	this->putString(message);
}

