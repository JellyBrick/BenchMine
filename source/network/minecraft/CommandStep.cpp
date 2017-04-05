#include "CommandStep.h"

CommandStep::CommandStep() : DataPacket(512) {
	this->unknown1 = 0;
	this->unknown2 = 0;
	this->unknown3 = false;
	this->unknown4 = 0;
}

void CommandStep::decode() {
	++this->position; // Skip Packet ID
	this->command = this->getVarString();
	this->overload = this->getVarString();
	this->unknown1 = this->getVarUInt();
	this->unknown2 = this->getVarUInt();
	this->unknown3 = this->getBool();
	this->unknown4 = this->getVarULong();
	this->args = this->getVarString();
	this->unknown5 = this->getVarString();
}