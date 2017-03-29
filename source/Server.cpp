#include "Server.h"

#include <cassert>

#include "network/minecraft/MinecraftPackets.h"
#include "common/Utils.h"
#include "world/entity/player/Player.h"

Server::Server() {
	this->maxPlayers = 20;
	this->ip = "0.0.0.0";
	this->port = 19132;
	this->motd = "Welcome to the BenchMine Server!";
	this->title = "BenchMine Minecraft Server!";
	this->raklib = std::make_unique<RakLib::RakLib>(this, this->ip, this->port);
	this->logger = std::make_unique<ColoredLogger>();
	this->scheduler = std::make_unique<TaskHandler>(MINECRAFT_TICK_RATE);

	Utils::setConsoleTitle("BenchMine Server Software");
	this->logger->info("BenchMine Server Software under LGPL v3");
}

void Server::start() {
	this->logger->info("Server at %s:%u - %s", ip.c_str(), this->port, this->title.c_str());

	this->scheduler->start();
	this->raklib->start();

	this->logger->info("Started RakLib...");
}

void Server::stop() {
	this->logger->info("Stopping server..");

	for (const auto& it : this->players) {
		it.second->close("Server Closing!");
	}

	this->scheduler->stop();
	this->raklib->stop();

	this->logger->info("Stopped RakLib");
}

void Server::addSession(const std::string& sessionIP, uint16 sessionPort, int64 clientID, int16 mtu) {
	if (this->getSession(sessionIP, sessionPort) != nullptr) {
		return;
	}

	this->logger->notice("New player have connected - %s:%u", sessionIP.c_str(), sessionPort);
	this->players[this->getSessionID(sessionIP, sessionPort)] = new Player(this, sessionIP, sessionPort, clientID, mtu);
}

void Server::removeSession(const std::string& sessionIP, uint16 sessionPort) {
	if (this->getSession(sessionIP, sessionPort) == nullptr) {
		return;
	}

	delete this->getSession(sessionIP, sessionPort);
}

RakLib::Session* Server::getSession(const std::string& sessionIP, uint16 sessionPort) {
	return this->players[this->getSessionID(sessionIP, sessionPort)];
}

std::string Server::getSessionID(const std::string& sessionIP, uint16 sessionPort) {
	return sessionIP + (":" + sessionPort);
}

int64 Server::getIdentifier() {
	return 123456789LL;
}

bool Server::useSecurity() {
	return false;
}

std::string Server::getType() {
	return "MCPE";
}

std::string Server::getName() {
	return title + motd;
}

int32 Server::getProtocol() {
	return NETWORK_PROTOCOL;
}

std::string Server::getGameVersion() {
	return GAME_VERSION;
}

uint32 Server::getActivePlayers() {
	return this->players.size();
}

uint32 Server::getMaxPlayer() {
	return maxPlayers;
}

Server::~Server() {
    this->stop();
}
