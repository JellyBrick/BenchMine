#include "SetTitle.h"

#include "MinecraftPackets.h"

SetTitle::SetTitle() : DataPacket(64) {
	this->action = Action::CLEAR_TITLE;
	this->fadeInTime = 0;
	this->stayTime = 0;
	this->fadeOutTime = 0;
}

void SetTitle::decode() {
	++this->position; // Skip Packet ID
	this->action = (Action)this->getVarUInt();
	this->text = this->getVarString();
	this->fadeInTime = this->getUInt();
	this->stayTime = this->getUInt();
	this->fadeOutTime = this->getUInt();
}

void SetTitle::encode() {
	this->putByte((uint8)MinecraftPackets::SetTitle);
	this->putVarUInt((uint32)this->action);
	this->putVarString(this->text);
	this->putVarUInt(this->fadeInTime);
	this->putVarUInt(this->stayTime);
	this->putVarUInt(this->fadeOutTime);
}