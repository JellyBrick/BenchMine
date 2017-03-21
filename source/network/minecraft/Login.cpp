#include "Login.h"
#include "MinecraftPackets.h"

Login::Login(std::unique_ptr<Packet> packet) : DataPacket(std::move(packet)) {
	this->username = "";
	this->clientID = 0;
	this->loginData = "";
	this->protocol = 0;
	this->protocol2 = 0;
}

void Login::decode() {
	if (this->getByte() != MinecraftPackets::LOGIN){
		return;
	}

	this->username = this->getString();
	this->protocol = this->getInt();
	this->protocol2 = this->getInt();
	this->clientID = this->getInt();
	this->loginData = this->getString();
}

