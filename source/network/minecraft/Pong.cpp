#include "MinecraftPackets.h"
#include "Pong.h"

Pong::Pong(int64 pingID) : DataPacket(9), pingID(pingID) {}

Pong::Pong(std::unique_ptr<Packet> packet) : DataPacket(std::move(packet)) {}

void Pong::decode() {
	// if (this->getByte() != MinecraftPackets::PONG)
	//		return;

	// this->pingID = this->getLong();
}

void Pong::encode() {
	// this->putByte(MinecraftPackets::PONG);
	// this->putLong(this->pingID);
}
