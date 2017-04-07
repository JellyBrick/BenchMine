#include "BlockEvent.h"

#include "MinecraftPackets.h"

BlockEvent::BlockEvent() : DataPacket(32) {
	case1 = 0;
	case2 = 0;
}

void BlockEvent::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::BlockEvent));
	Vector3i::serialize(blockPosition, *this);
	putVarUInt(case1);
	putVarUInt(case2);
}