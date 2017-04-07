#include "EntityEvent.h"

#include "MinecraftPackets.h"

EntityEvent::EntityEvent() : DataPacket(16) {
	entityID = 0;
	event = 0x00;
	unknown = 0;
}

void EntityEvent::decode() {
	++position; // Skip Packet ID
	entityID = getVarULong();
	event = getByte();
	unknown = getVarUInt();
}

void EntityEvent::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::EntityEvent));
	putVarULong(entityID);
	putByte(event);
	putVarUInt(unknown);
}