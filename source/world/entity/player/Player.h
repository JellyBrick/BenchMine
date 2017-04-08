#pragma once

#include "world/entity/Entity.h"
#include "world/math/Vector3f.h"

class Server;
class NetworkSession;
class Player : public Entity {
	friend NetworkSession;

private:
	Server* server;
	
	std::string ip;
	uint16 port;

	int CID;
	std::string username;
	std::string lowerUserName;
	Vector3f spawnPosition;

public:
	Player(Server* server, const std::string& sessionIP, uint16 sessionPort);

	void onRemove() override;

	void setUsername(const std::string& newUsername);
	const std::string& getUsername() const;
	std::string getLUsername() const;
};