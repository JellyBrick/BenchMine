#include "AdventureSettings.h"

#include "MinecraftPackets.h"
#include "network/raknet/RaknetPackets.h"

AdventureSettings::AdventureSettings(uint32 userPerm, uint32 flag) : RakLib::DataPacket(10) {
	this->userPermission = userPerm;
	this->flags = flag;
}

void AdventureSettings::encode() {
	this->putByte((uint8)RaknetPacket::WRAPPER);
	this->putByte((uint8)MinecraftPackets::ADVENTURE_SETTINGS);
	this->putUInt(this->flags);
	this->putUInt(this->userPermission);
}
