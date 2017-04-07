#include "Server.h"

#include <cassert>

#include "common/Utils.h"
#include "network/minecraft/MinecraftPackets.h"
#include "world/entity/player/Player.h"

Server::Server() {
	maxPlayers = 20;
	ip = "0.0.0.0";
	port = 19132;
	motd = "Welcome to the BenchMine Server!";
	title = "BenchMine Minecraft Server!";
	raklib = std::make_unique<RakLib::RakLib>(this, ip, port);
	logger = std::make_unique<ColoredLogger>();
	scheduler = std::make_unique<TaskHandler>(MINECRAFT_TICK_RATE);
	level = std::make_unique<Level>(2);

	Utils::setConsoleTitle("BenchMine Server Software");
	logger->info("BenchMine Server Software under LGPL v3");
}

void Server::start() {
	logger->info("Server at %s:%u - %s", ip.c_str(), port, title.c_str());

	scheduler->start();
	raklib->start();

	logger->info("Started RakLib...");
}

void Server::stop() {
	logger->info("Stopping server..");

	for (const auto& it : players) {
		it.second->disconnect("Server Closing!");
	}

	scheduler->stop();
	raklib->stop();

	logger->info("Stopped RakLib");
}

void Server::addSession(const std::string& sessionIP, uint16 sessionPort, int64 clientID, int16 mtu) {
	if (getSession(sessionIP, sessionPort) != nullptr) {
		return;
	}

	logger->notice("New player have connected - %s:%u", sessionIP.c_str(), sessionPort);
	players[getSessionID(sessionIP, sessionPort)] = new Player(this, sessionIP, sessionPort, clientID, mtu);
}

void Server::removeSession(const std::string& sessionIP, uint16 sessionPort) {
	if (getSession(sessionIP, sessionPort) == nullptr) {
		return;
	}

	delete getSession(sessionIP, sessionPort);
}

RakLib::Session* Server::getSession(const std::string& sessionIP, uint16 sessionPort) {
	return players[getSessionID(sessionIP, sessionPort)];
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
	return players.size();
}

uint32 Server::getMaxPlayer() {
	return maxPlayers;
}

Server::~Server() {
    stop();
}
