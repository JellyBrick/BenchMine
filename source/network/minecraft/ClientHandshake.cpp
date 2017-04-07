#include "ClientHandshake.h"

ClientHandshake::ClientHandshake(std::unique_ptr<Packet>&& packet) : RakLib::DataPacket(std::move(packet)) {}

void ClientHandshake::decode() {
	getByte(); // Skip Packet ID
	// TODO
}