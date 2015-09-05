#include "Network\Minecraft\Pong.h"
#include "Network\Minecraft\MinecraftPackets.h"

Pong::Pong(long pingID) : DataPacket(9)
{
	this->pingID = pingID;
}

Pong::Pong(Packet* packet) : DataPacket(packet) {}

void Pong::decode()
{
	if (this->getByte() != MinecraftPackets::PONG)
		return;

	this->pingID = this->getLong();
}

void Pong::encode()
{
	this->putByte(MinecraftPackets::PONG);
	this->putLong(this->pingID);
}
