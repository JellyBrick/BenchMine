#include "ConnectionRequest.h"

ConnectionRequest::ConnectionRequest(std::unique_ptr<RakLib::Packet>&& packet) : DataPacket(std::move(packet)) {
	clientID = 0;
	sendPing = 0;
	useSecurity = false;
}

void ConnectionRequest::decode() {
	++position; // Skip Packet ID

	clientID = getLong();
	sendPing = getULong();
	useSecurity = getBool();
}
