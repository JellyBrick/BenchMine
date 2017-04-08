#include "ConnectionAccepted.h"

#include "RaknetPackets.h"
#include "common/Utils.h"

ConnectionAccepted::ConnectionAccepted(const std::string& clientIP, uint16 clientPort, int64 sendPing, int64 sendPong) : DataPacket(96), sendPing(sendPing), sendPong(sendPong) {
	ip = clientIP;
	port = clientPort;
}

void ConnectionAccepted::encode() {
	putByte(static_cast<uint8>(RaknetPacket::CONNECTION_ACCEPTED));
	putAddress(ip, port);
	putShort(0);

	putAddress("127.0.0.1", 0);
	for (uint32 i = 0; i < 9; ++i) {
		putAddress("0.0.0.0", 0);
	}
	
	putLong(sendPing);
	putLong(sendPong);
}

void ConnectionAccepted::putAddress(const std::string& address, uint16 port_) {
	putByte(0x04); // IPV4(4) or IPV6(6)
	std::vector<std::string> numbers = Utils::explode(address, '.');
	for (const auto& it : numbers) {
		int value = atoi(it.c_str());
		putChar(static_cast<int8>(~value & 0xff));
	}
	putUShort(static_cast<uint16>(port_));
}
