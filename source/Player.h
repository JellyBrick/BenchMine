#pragma once

#include <Session.h>

#include "Entity\Entity.h"

class Server;
class Player : public Entity, public RakLib::Session {
private:
	Server* server;
	int CID;
	std::string username;
	std::string lowerUserName;

public:
	Player(Server* server, const std::string& ip, uint16 port, int64 clientID, int16 mtuSize);

	void close(const std::string& reason);

	void handleDataPacket(std::unique_ptr<RakLib::DataPacket> packet) override;
	void sendPacket(const RakLib::Packet& packet) override;

	const std::string& getUsername() const { return this->username; }
	std::string getLUsername() const { return this->lowerUserName; }
};