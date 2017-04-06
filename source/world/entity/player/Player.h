#pragma once

#include <packets/DataPacket.h>
#include <Session.h>

#include "world/entity/Entity.h"

class Server;
class Player : public Entity, public RakLib::Session {
private:
	Server* server;
	int CID;
	std::string username;
	std::string lowerUserName;

public:
	Player(Server* server, const std::string& ip, uint16 port, int64 clientID, int16 mtuSize);

	void disconnect(const std::string& reason);

	void update() override;

	void handleDataPacket(std::unique_ptr<RakLib::Packet> packet) override;
	
	void handleGamePacket(std::unique_ptr<RakLib::Packet> packet);

	void addDataPacket(std::unique_ptr<RakLib::DataPacket>&& packet, QueuePriority priority);

	void sendPacket(RakLib::Packet& packet) override;

	void postLogin();

	const std::string& getUsername() const { return this->username; }
	std::string getLUsername() const { return this->lowerUserName; }

};