#pragma once

#include <RakLib/protocol/DataPacket.h>

#include "common/jsonxx.h"

class Login : public RakLib::DataPacket
{
public:
	int32 protocol;
	uint8 edition;
	
	std::string displayName;
	std::string clientUUID;
	std::string identityPublicKey;

public:
	Login(std::unique_ptr<Packet>&& packet);
	void decode() override;

private:
	jsonxx::Object getRealChain(const std::string& json) const;
};
