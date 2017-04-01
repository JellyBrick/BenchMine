#include "AdventureSettings.h"

#include "MinecraftPackets.h"
#include "network/raknet/RaknetPackets.h"

AdventureSettings::AdventureSettings(uint32 userPerm, uint32 flag) : RakLib::DataPacket(9) {
	this->userPermission = userPerm;
	this->flags = flag;
}

void AdventureSettings::encode() {
	this->putByte((uint8)MinecraftPackets::ADVENTURE_SETTINGS);
	this->putVarUInt(this->flags);
	this->putVarUInt(this->userPermission);
}