#include "ServerHandshake.h"

#include "MinecraftPackets.h"

ServerHandshake::ServerHandshake(const std::string& serverPublicKey, uint32 tokenLength, uint8* tokens) : 
	RakLib::DataPacket(7 + serverPublicKey.length() + tokenLength), serverPublicKey(serverPublicKey), tokenLength(tokenLength), tokens(tokens) {}

void ServerHandshake::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::ServerHandshake));
	putString(serverPublicKey);
	putUInt(tokenLength);
	if (tokenLength > 0 && tokens != nullptr) {
		putByte(tokens, tokenLength);
	}
}