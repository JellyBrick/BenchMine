#include "SetTitle.h"

#include "MinecraftPackets.h"

SetTitle::SetTitle() : DataPacket(64) {
	action = Action::CLEAR_TITLE;
	fadeInTime = 0;
	stayTime = 0;
	fadeOutTime = 0;
}

void SetTitle::decode() {
	++position; // Skip Packet ID
	action = (Action)getVarUInt();
	text = getVarString();
	fadeInTime = getUInt();
	stayTime = getUInt();
	fadeOutTime = getUInt();
}

void SetTitle::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::SetTitle));
	putVarUInt(static_cast<uint32>(action));
	putVarString(text);
	putVarUInt(fadeInTime);
	putVarUInt(stayTime);
	putVarUInt(fadeOutTime);
}