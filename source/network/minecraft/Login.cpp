#include "Login.h"
#include "MinecraftPackets.h"

Login::Login(Packet* pck) : DataPacket(pck) {
	this->username = "";
	this->clientID = 0;
	this->loginData = "";
	this->protocol = 0;
	this->protocol2 = 0;
}

void Login::decode() {
	if (this->getByte() != MinecraftPackets::LOGIN_PACKET){
		throw std::runtime_error("Expected another packet.");
	}

	this->username = this->getString();
	this->protocol = this->getInt();
	this->protocol2 = this->getInt();
	this->clientID = this->getInt();
	this->loginData = this->getString();
}

