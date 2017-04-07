#include "LevelEvent.h"

#include "MinecraftPackets.h"

LevelEvent::LevelEvent() : DataPacket(32) {
	eventID = Event::NONE;
	data = 0;
}

void LevelEvent::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::LevelEvent));
	putVarUInt(static_cast<uint32>(eventID));
	Vector3f::serialize(eventPosition, *this);
	putVarUInt(data);
}