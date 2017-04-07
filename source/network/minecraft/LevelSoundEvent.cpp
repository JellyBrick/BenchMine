#include "LevelSoundEvent.h"

#include "MinecraftPackets.h"

LevelSoundEvent::LevelSoundEvent() : DataPacket(32) {
	eventID = Event::UNDEFINED;
	extraData = 0;
	pitch = 0;
	unknown1 = false;
	unknown2 = false;
}

void LevelSoundEvent::decode() {
	++position; // Skip Packet ID
	eventID = (Event)getByte();
	eventPosition = Vector3f::deserialize(*this);
	extraData = getVarUInt();
	pitch = getVarUInt();
	unknown1 = getBool();
	unknown2 = getBool();
}

void LevelSoundEvent::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::LevelSoundEvent));
	putByte(static_cast<uint8>(eventID));
	Vector3f::serialize(eventPosition, *this);
	putVarUInt(extraData);
	putVarUInt(pitch);
	putBool(unknown1);
	putBool(unknown2);
}