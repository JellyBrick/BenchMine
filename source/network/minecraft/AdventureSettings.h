#pragma once

#include <RakLib/protocol/DataPacket.h>

class AdventureSettings : public RakLib::DataPacket {
public:
	enum PERMISSIONS  : uint32 {
		NORMAL, OPERATOR, HOST, AUTOMATION, ADMIN
	};

	uint32 userPermission;
	uint32 flags;

	AdventureSettings(uint32 userPerm, uint32 flag);

	void encode() override;
};