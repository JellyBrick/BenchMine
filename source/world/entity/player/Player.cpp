#include "Player.h"

#include <algorithm>

#include "Server.h"

Player::Player(Server* server, const std::string& sessionIP, uint16 sessionPort) : server(server), ip(sessionIP), port(sessionPort), CID(0) {
	spawnPosition = { 0.0f, 8.0f, 0.0f };
}

void Player::onRemove() {
	Entity::onRemove();

	server->getLogger()->notice("%s (%s:%d) connection have been terminated", username.c_str(), ip.c_str(), port);
}

void Player::setUsername(const std::string& newUsername) {
	lowerUserName = username = newUsername;
	std::transform(username.begin(), username.end(), lowerUserName.begin(), ::tolower);
}

const std::string& Player::getUsername() const {
	return username;
}

std::string Player::getLUsername() const {
	return lowerUserName;
}