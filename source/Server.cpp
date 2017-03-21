#include "Server.h"

#include "Player.h"
#include "Utils.h"

Server::Server() {
	Utils::setConsoleTitle("BenchMine Server Software");

	this->maxPlayers = 10;
	this->ip = "0.0.0.0";
	this->port = 19132;
	this->motd = "Welcome to the BenchMine Server!";
	this->title = "BenchMine Minecraft Server!";
	this->raklib = std::make_unique<RakLib::RakLib>(this, "", 19132);
	this->logger = std::make_unique<ColoredLogger>();
	this->scheduler = std::make_unique<TaskHandler>(MINECRAFT_TICK_RATE); // Default Minecraft Tick Rate
	this->logger->info("BenchMine Server Software under LGPL v3");
}

void Server::start() {
	this->logger->info("Server at %s:%u - %s", this->ip.c_str(), this->port, this->title.c_str());

	this->scheduler->start();
	this->raklib->start();

	this->logger->info("Started RakLib...");
}

void Server::stop() {
	this->logger->info("Stopping server..");

	this->scheduler->stop();
	this->raklib->stop();

	this->logger->info("Stopped RakLib");
}

void Server::addSession(const std::string& ip, uint16 port, int64 clientID, int16 mtu) {
	this->logger->notice("New player have connected - %s:%d", ip.c_str(), port);
	this->players[ip] = new Player(this, ip, port, clientID, mtu);
}

void Server::removeSession(const std::string& ip, unsigned short port) {
	if (this->players[this->getSessionID(ip, port)] == nullptr) {
	}

	delete this->getSession(ip, port);
}

RakLib::Session* Server::getSession(const std::string& ip, uint16 port) {
	return this->players[this->getSessionID(ip, port)];
}

std::string Server::getSessionID(const std::string& ip, uint16 port) {
	return ip + (":" + port);
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
	return 105;
}

std::string Server::getGameVersion() {
	return "1.0.5";
}

uint32 Server::getActivePlayers() {
	return 0;
}

uint32 Server::getMaxPlayer() {
	return 20;
}

Server::~Server() {
    this->stop();
}
