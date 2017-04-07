#include "AdventureSettings.h"

#include "MinecraftPackets.h"

AdventureSettings::AdventureSettings(uint32 userPerm, uint32 flag) 
	: RakLib::DataPacket(9), userPermission(userPermission), flags(flag) {}

void AdventureSettings::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::AdventureSettings));
	putVarUInt(flags);
	putVarUInt(userPermission);
}