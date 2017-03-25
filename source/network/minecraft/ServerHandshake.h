#pragma once

#include <string>

#include <packets/DataPacket.h>

class ServerHandshake : public RakLib::DataPacket {
public:
	std::string serverPublicKey;
	uint32 tokenLength;
	uint8* tokens;

public:
	ServerHandshake(const std::string& serverPublicKey, uint32 tokenLength, uint8* tokens);
	void encode() override;
};