#pragma once

#include <Session.h>

#include "Entity\Entity.h"

class Server;
class Player : public Entity, public RakLib::Session
{
private:
	std::string username;
	int CID;
	Server* server;

public:
	Player(Server* server, std::string ip, uint16 port, int64 clientID, int16 mtuSize);
	~Player();

	void close(const std::string& reason);

	void handleDataPacket(std::unique_ptr<RakLib::DataPacket> packet) override;
	void sendPacket(std::unique_ptr<RakLib::Packet> packet);

	const std::string& getUsername() const { return this->username; }
	const std::string getLUsername();

};