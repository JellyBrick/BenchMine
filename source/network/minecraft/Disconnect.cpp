#include "Disconnect.h"

#include "MinecraftPackets.h"
#include "network/raknet/RaknetPackets.h"

Disconnect::Disconnect(const std::string& message) : RakLib::DataPacket(5 + message.length()),
	messageHided(message.empty()), message(message) {}

void Disconnect::encode() {
	this->putByte((uint8)RaknetPacket::WRAPPER);
	this->putByte((uint8)MinecraftPackets::DISCONNECT);
	this->putBool(messageHided);
	this->putString(message);
}

