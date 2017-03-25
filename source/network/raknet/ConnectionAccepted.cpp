#include "ConnectionAccepted.h"

#include "..\..\Utils.h"
#include "RaknetPackets.h"

ConnectionAccepted::ConnectionAccepted(const std::string& ip, uint16 port, int64 sendPing, int64 sendPong) : DataPacket(96) {
	this->ip = ip;
	this->port = port;
	this->sendPing = sendPing;
	this->sendPong = sendPong;
}

void ConnectionAccepted::encode() {
	this->putByte(CONNECTION_ACCEPTED);
	this->putAddress(this->ip, this->port);
	this->putShort(0);

	this->putAddress("127.0.0.1", 0);
	for (uint32 i = 0; i < 9; ++i) {
		this->putAddress("0.0.0.0", 0);
	}
	
	this->putLong(this->sendPing);
	this->putLong(this->sendPong);
}

void ConnectionAccepted::putAddress(const std::string& address, uint16 port) {
	this->putByte(4); // This should be the version of the ip. IPV4(4) or IPV6(6)
	std::vector<std::string> numbers = Utils::explode(address, '.');
	for (const auto& it : numbers) {
		int value = atoi(it.c_str());
		this->putChar((int8)(~value & 0xff));
	}
	this->putUShort((uint16)port);
}