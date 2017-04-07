#include "Player.h"

#include <algorithm>

#include "Server.h"

Player::Player(Server* server) : server(server), CID(0) {
	spawnPosition = { 0.0f, 8.0f, 0.0f };
}

void Player::onRemove() {
	Entity::onRemove();

	server->getLogger()->notice("%s connection have been terminated", username.c_str());
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