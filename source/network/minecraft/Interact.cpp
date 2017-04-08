#include "Interact.h"

#include "MinecraftPackets.h"

Interact::Interact() : DataPacket(16) {
	action = Action::NONE;
	entityID = 0;
}

void Interact::decode() {
	++position; // Skip Packet ID
	action = (Action)getByte();
	entityID = getVarULong();
}

void Interact::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::Interact));
	putByte(static_cast<uint8>(action));
	putVarULong(entityID);
}