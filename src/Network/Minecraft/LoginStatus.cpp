#include "Network\Minecraft\LoginStatus.h"
#include "Network\Minecraft\MinecraftPackets.h"

LoginStatus::LoginStatus(int status) : DataPacket(5)
{
	this->status = status;
}


void LoginStatus::encode()
{
	this->putByte(MinecraftPackets::LOGIN_STATUS_PACKET);
	this->putInt(this->status);
}
