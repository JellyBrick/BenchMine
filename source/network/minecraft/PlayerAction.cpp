#include "PlayerAction.h"

#include "MinecraftPackets.h"

PlayerAction::PlayerAction() : DataPacket(64) {
	entityID = 0;
	action = Action::START_BREAK;
	face = face;
}

void PlayerAction::decode() {
	++position; // Skip Packet ID
	entityID = getVarULong();
	action = (Action)getVarUInt();
	entityPosition = Vector3f::deserialize(*this);
	face = getVarUInt();
}

void PlayerAction::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::PlayerAction));
	putVarULong(entityID);
	putVarUInt(action);
	Vector3f::serialize(entityPosition, *this);
	putVarUInt(face);
}