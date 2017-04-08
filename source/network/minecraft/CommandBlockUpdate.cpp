#include "CommandBlockUpdate.h"

#include "MinecraftPackets.h"

CommandBlockUpdate::CommandBlockUpdate() : DataPacket(256) {
	isBlock = false;
	commandBlockMode = 0;
	isRedstoneMode = false;
	isConditionalMode = false;
	minecartEntityID = 0;
	shouldTrackOutput = false;
}

void CommandBlockUpdate::decode() {
	++position; // Skip packet id;
	isBlock = getBool();

	if (isBlock) {
		blockPosition = Vector3i::deserialize(*this);
		commandBlockMode = getVarUInt();
		isRedstoneMode = getBool();
		isConditionalMode = getBool();
	} else {
		minecartEntityID = getVarULong();
	}

	command = getVarString();
	lastCommandOutput = getVarString();
	name = getVarString();

	shouldTrackOutput = getBool();
}

void CommandBlockUpdate::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::CommandBlockUpdate));
	putBool(isBlock);

	if (isBlock) {
		Vector3i::serialize(blockPosition, *this);
		putVarUInt(commandBlockMode);
		putBool(isRedstoneMode);
		putBool(isConditionalMode);
	} else {
		putVarULong(minecartEntityID);
	}

	putVarString(command);
	putVarString(lastCommandOutput);
	putVarString(name);

	putBool(shouldTrackOutput);
}