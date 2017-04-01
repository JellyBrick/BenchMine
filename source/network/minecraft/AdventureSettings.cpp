#include "AdventureSettings.h"

#include "MinecraftPackets.h"

AdventureSettings::AdventureSettings(uint32 userPerm, uint32 flag) : RakLib::DataPacket(9) {
	this->userPermission = userPerm;
	this->flags = flag;
}

void AdventureSettings::encode() {
	this->putByte((uint8)MinecraftPackets::AdventureSettings);
	this->putVarUInt(this->flags);
	this->putVarUInt(this->userPermission);
}