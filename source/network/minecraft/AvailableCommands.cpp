#include "AvailableCommands.h"

#include "MinecraftPackets.h"

AvailableCommands::AvailableCommands() : DataPacket(128) {}

void AvailableCommands::encode() {
	this->putByte((uint8)MinecraftPackets::AvailableCommands);
	this->putString(this->commands);
	this->putString(this->unknown);
}
