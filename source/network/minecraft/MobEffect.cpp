#include "MobEffect.h"

#include "MinecraftPackets.h"

MobEffect::MobEffect() : DataPacket(64) {
	entityID = 0;
	eventID = Event::ADD;
	effectID = 0;
	amplifier = 0;
	particles = true;
	duration = 0;
}

void MobEffect::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::MobEffect));
	putVarULong(entityID);
	putByte(static_cast<uint8>(eventID));
	putVarUInt(effectID);
	putVarUInt(amplifier);
	putBool(particles);
	putVarUInt(duration);
}