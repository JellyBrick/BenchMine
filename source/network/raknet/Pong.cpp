#include "Pong.h"

#include "RaknetPackets.h"

Pong::Pong(std::unique_ptr<Packet>&& packet) : DataPacket(std::move(packet)), pingID(0){}

Pong::Pong(uint64 pingID) : DataPacket(9), pingID(pingID) {}

void Pong::decode() {
	++position; // Skip Packet ID

	pingID = getULong();
}

void Pong::encode() {
	putByte(static_cast<uint8>(RaknetPacket::PONG));
	putULong(pingID);
}