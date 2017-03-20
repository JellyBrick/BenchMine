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

	void handleDataPacket(RakLib::DataPacket* packet);
	void sendPacket(RakLib::Packet* packet);

	inline const std::string& getUsername() const { this->username; };
	const std::string getLUsername();

};