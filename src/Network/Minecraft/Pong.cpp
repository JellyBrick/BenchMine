#include "Network/Minecraft/Pong.h"

Pong::Pong(long pingID) : DataPacket(9)
{
	this->pingId = pingID;
}

void Pong::decode()
{}

void Pong::encode()
{}
