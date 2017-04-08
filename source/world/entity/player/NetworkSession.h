#pragma once

#include <RakLib/protocol/DataPacket.h>
#include <RakLib/Session.h>

class Server;
class Player;

class NetworkSession : public RakLib::Session {
private:
	Server* server;
	Player* player;

public:
	NetworkSession(Server* server, const std::string& ip, uint16 port, int64 clientID, uint16 mtuSize);

	void update() override;

	void handleDataPacket(std::unique_ptr<RakLib::Packet> packet) override;

	void handleGamePacket(std::unique_ptr<RakLib::Packet> packet);

	void addDataPacket(std::unique_ptr<RakLib::DataPacket>&& packet, QueuePriority priority);

	void sendPacket(RakLib::Packet& packet) override;

	void disconnect(const std::string& reason);

	void postLogin();

	void addPlayerToLevel();
};