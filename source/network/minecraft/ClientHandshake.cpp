#include "ClientHandshake.h"

#include <cassert>

#include "MinecraftPackets.h"

ClientHandshake::ClientHandshake(std::unique_ptr<Packet> packet) : RakLib::DataPacket(std::move(packet)) {}

void ClientHandshake::decode() {
	assert(this->getByte() == CLIENT_HANDSHAKE);
	// NOTHING
}
