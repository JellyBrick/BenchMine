#include "PlaySound.h"

#include "MinecraftPackets.h"

PlaySound::PlaySound() : DataPacket(64){
	unknown1 = 0.0f;
	unknown2 = 0.0f;
}

void PlaySound::decode() {
	++position; // Skip Packet ID
	soundID = getVarString();
	eventPosition = Vector3i::deserialize(*this);
	unknown1 = getFloat();
	unknown2 = getFloat();
}

void PlaySound::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::PlaySound));
	putVarString(soundID);
	Vector3i::serialize(eventPosition, *this);
	putFloat(unknown1);
	putFloat(unknown2);
}