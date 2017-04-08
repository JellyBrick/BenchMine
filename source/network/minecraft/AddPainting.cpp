#include "AddPainting.h"

#include "MinecraftPackets.h"

// TODO: Remove placeholder packet size
AddPainting::AddPainting() : DataPacket(128){
	entityId = 0;
	direction = 0x00;
}

void AddPainting::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::AddPainting));
	putVarULong(entityId);
	putVarULong(entityId); // RuntimeEntityID
	Vector3i::serialize(blockPosition, *this);
	putByte(direction);
	putString(title);
}