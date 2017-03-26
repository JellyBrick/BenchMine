#include "Login.h"
#include "MinecraftPackets.h"

Login::Login(std::unique_ptr<Packet>&& packet) : DataPacket(std::move(packet)) {
	this->protocol = 0;
	this->edition = 0x00;
	this->payload = nullptr;
}

void Login::decode() {
	if (this->getByte() != LOGIN) {
		return;
	}

	this->protocol = this->getInt();
	this->edition = this->getByte();
	this->payload = this->getByte(this->length - this->position);
}

