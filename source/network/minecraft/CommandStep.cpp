#include "CommandStep.h"

CommandStep::CommandStep() : DataPacket(512) {
	unknown1 = 0;
	unknown2 = 0;
	unknown3 = false;
	unknown4 = 0;
}

void CommandStep::decode() {
	++position; // Skip Packet ID
	command = getVarString();
	overload = getVarString();
	unknown1 = getVarUInt();
	unknown2 = getVarUInt();
	unknown3 = getBool();
	unknown4 = getVarULong();
	args = getVarString();
	unknown5 = getVarString();
}