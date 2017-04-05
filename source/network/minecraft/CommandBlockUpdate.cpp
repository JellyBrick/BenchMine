#include "CommandBlockUpdate.h"

#include "MinecraftPackets.h"

CommandBlockUpdate::CommandBlockUpdate() : DataPacket(256) {
	this->isBlock = false;
	this->commandBlockMode = 0;
	this->isRedstoneMode = false;
	this->isConditionalMode = false;
	this->minecartEntityID = 0;
	this->shouldTrackOutput = false;
}

void CommandBlockUpdate::decode() {
	++this->position; // Skip packet id;
	this->isBlock = this->getBool();

	if (this->isBlock) {
		this->blockPosition = Vector3i::deserialize(*this);
		this->commandBlockMode = this->getVarUInt();
		this->isRedstoneMode = this->getBool();
		this->isConditionalMode = this->getBool();
	} else {
		this->minecartEntityID = this->getVarULong();
	}

	this->command = this->getVarString();
	this->lastCommandOutput = this->getVarString();
	this->name = this->getVarString();

	this->shouldTrackOutput = this->getBool();
}

void CommandBlockUpdate::encode() {
	this->putByte((uint8)MinecraftPackets::CommandBlockUpdate);
	this->putBool(this->isBlock);

	if (this->isBlock) {
		Vector3i::serialize(this->blockPosition, *this);
		this->putVarUInt(this->commandBlockMode);
		this->putBool(this->isRedstoneMode);
		this->putBool(this->isConditionalMode);
	} else {
		this->putVarULong(this->minecartEntityID);
	}

	this->putVarString(this->command);
	this->putVarString(this->lastCommandOutput);
	this->putVarString(this->name);

	this->putBool(this->shouldTrackOutput);
}