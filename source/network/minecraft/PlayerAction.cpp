#include "PlayerAction.h"

#include "MinecraftPackets.h"

PlayerAction::PlayerAction() : DataPacket(64) {
	this->entityID = 0;
	this->action = Action::START_BREAK;
	this->face = face;
}

void PlayerAction::decode() {
	++this->position; // Skip Packet ID
	this->entityID = this->getVarULong();
	this->action = (Action)this->getVarUInt();
	this->entityPosition = Vector3f::deserialize(*this);
	this->face = this->getVarUInt();
}

void PlayerAction::encode() {
	this->putByte((uint8)MinecraftPackets::PlayerAction);
	this->putVarULong(this->entityID);
	this->putVarUInt(action);
	Vector3f::serialize(this->entityPosition, *this);
	this->putVarUInt(this->face);
}