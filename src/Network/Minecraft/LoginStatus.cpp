/**
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* @author InusualZ
*
*
*/

#include "Network\Minecraft\LoginStatus.h"
#include "Network\Minecraft\MinecraftPackets.h"

LoginStatus::LoginStatus(int status) : DataPacket(5) {
	this->status = status;
}


void LoginStatus::encode() {
	this->putByte(MinecraftPackets::LOGIN_STATUS_PACKET);
	this->putInt(this->status);
}
