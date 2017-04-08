#include "UpdateAttributes.h"

#include "MinecraftPackets.h"

UpdateAttributes::UpdateAttributes() : DataPacket(64) {
	entityID = 0;
}

void UpdateAttributes::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::UpdateAttributes));
	putVarULong(entityID);
	// EntityAttributes::serialize
}