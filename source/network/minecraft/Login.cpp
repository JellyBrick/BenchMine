#include "Login.h"

Login::Login(std::unique_ptr<Packet>&& packet) : DataPacket(std::move(packet)) {
	this->protocol = 0;
	this->edition = 0x00;
	this->payload = nullptr;
}

void Login::decode() {
	this->position = 2; // Skip Wrapper and Packet ID

	this->protocol = this->getInt();
	this->edition = this->getByte();
	this->payload = this->getByte(this->length - this->position);
}

