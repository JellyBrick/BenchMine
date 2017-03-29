#include "ServerHandshake.h"

#include "MinecraftPackets.h"

ServerHandshake::ServerHandshake(const std::string& serverPublicKey, uint32 tokenLength, uint8* tokens) : 
	RakLib::DataPacket(7 + serverPublicKey.length() + tokenLength), serverPublicKey(serverPublicKey), tokenLength(tokenLength), tokens(tokens) {}

void ServerHandshake::encode() {
	this->putByte((uint8)MinecraftPackets::SERVER_HANDSHAKE);
	this->putString(this->serverPublicKey);
	this->putUInt(this->tokenLength);
	if (this->tokenLength > 0 && this->tokens != nullptr) {
		this->putByte(this->tokens, this->tokenLength);
	}
}

