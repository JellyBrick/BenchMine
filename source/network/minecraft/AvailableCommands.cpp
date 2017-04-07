#include "AvailableCommands.h"

#include "MinecraftPackets.h"

AvailableCommands::AvailableCommands() : DataPacket(128) {}

void AvailableCommands::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::AvailableCommands));
	putString(commands);
	putString(unknown);
}
