#include "UpdateAttributes.h"

#include "MinecraftPackets.h"

UpdateAttributes::UpdateAttributes() : DataPacket(64) {
	this->entityID = 0;
}

void UpdateAttributes::encode() {
	this->putByte((uint8)MinecraftPackets::UpdateAttributes);
	this->putVarULong(this->entityID);
	// EntityAttributes::serialize
}