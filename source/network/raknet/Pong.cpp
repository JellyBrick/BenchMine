#include "Pong.h"

#include "RaknetPackets.h"

Pong::Pong(std::unique_ptr<Packet>&& packet) : DataPacket(std::move(packet)), pingID(0){}

Pong::Pong(uint64 pingID) : DataPacket(9), pingID(pingID) {}

void Pong::decode() {
	++this->position; // Skip Packet ID

	this->pingID = this->getULong();
}

void Pong::encode() {
	this->putByte((uint8)RaknetPacket::PONG);
	this->putULong(this->pingID);
}
