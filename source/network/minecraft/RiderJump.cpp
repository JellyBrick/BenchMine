#include "RiderJump.h"

#include "MinecraftPackets.h"

RiderJump::RiderJump() : DataPacket(8) {
	unknown = 0;
}

void RiderJump::decode() {
	++position; // Skip Packet ID
	unknown = getVarUInt();
}

void RiderJump::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::RiderJump));
	putVarUInt(unknown);
}