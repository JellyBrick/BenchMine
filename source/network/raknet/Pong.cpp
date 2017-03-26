#include "Pong.h"

#include "RaknetPackets.h"

Pong::Pong(std::unique_ptr<Packet>&& packet) : DataPacket(std::move(packet)), pingID(0){}

Pong::Pong(int64 pingID) : DataPacket(9), pingID(pingID) {}

void Pong::decode() {
	 if (this->getByte() != PONG)
			return;

	 this->pingID = this->getULong();
}

void Pong::encode() {
	this->putByte(PONG);
	this->putULong(this->pingID);
}
