#include "ShowCredits.h"

#include "MinecraftPackets.h"

ShowCredits::ShowCredits() : DataPacket(16) {
	entityID = 0;
	action = Action::START;
}

void ShowCredits::decode() {
	++position; // Skip Packet ID;
	entityID = getVarULong();
	action = (Action)getVarUInt();
}

void ShowCredits::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ShowCredits));
	putVarULong(entityID);
	putVarUInt((Action)action);
}