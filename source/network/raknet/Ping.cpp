#include "Ping.h"

#include "RaknetPackets.h"

Ping::Ping(std::unique_ptr<RakLib::Packet>&& packet) : DataPacket(std::move(packet)), pingID(0) {}

Ping::Ping(int64 pingID) : DataPacket(9), pingID(pingID) {}

void Ping::decode() {
	++position; // Skip Packet ID

	pingID = getLong();
}

void Ping::encode() {
	putByte(static_cast<uint8>(RaknetPacket::PING));
	putLong(pingID);
}