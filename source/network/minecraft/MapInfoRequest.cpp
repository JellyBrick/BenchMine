#include "MapInfoRequest.h"

#include "MinecraftPackets.h"

MapInfoRequest::MapInfoRequest() : DataPacket(8) {
	this->mapID = 0;
}

void MapInfoRequest::encode() {
	this->putByte((uint8)MinecraftPackets::MapInfoRequest);
	this->putVarULong(this->mapID);
}