#include "MapInfoRequest.h"

#include "MinecraftPackets.h"

MapInfoRequest::MapInfoRequest() : DataPacket(8) {
	mapID = 0;
}

void MapInfoRequest::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::MapInfoRequest));
	putVarULong(mapID);
}