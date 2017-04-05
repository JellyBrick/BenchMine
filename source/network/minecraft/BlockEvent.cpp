#include "BlockEvent.h"

#include "MinecraftPackets.h"

BlockEvent::BlockEvent() : DataPacket(32) {
	case1 = 0;
	case2 = 0;
}

void BlockEvent::encode() {
	this->putByte((uint8)MinecraftPackets::BlockEvent);
	Vector3i::serialize(this->blockPosition, *this);
	this->putVarUInt(this->case1);
	this->putVarUInt(this->case2);
}