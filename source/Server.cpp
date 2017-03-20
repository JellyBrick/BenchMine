#include "Server.h"

#include "Player.h"

Server::Server() {
	this->_maxPlayers = 10;
	this->_ip = "0.0.0.0";
	this->_port = 19132;
	this->_motd = "Welcome to the BenchMine Server!";
	this->_title = "BenchMine Minecraft Server!";
	this->_raklib = new RakLib::RakLib(this, "", 19132);
	this->_logger = new ColoredLogger();
	this->_scheduler = new TaskHandler(20); // Default Minecraft Tick Rate

#ifdef WIN32
	SetConsoleTitle("BenchMine Server Software");
#else // Unix
	//TODO
#endif 

	this->_logger->info("BenchMine Server Software under LGPL v3");
}

void Server::start() {
	this->_logger->info("Server at %s:%d - %s", this->_ip.c_str(), this->_port, this->_title.c_str());

	this->_scheduler->start();
	this->_raklib->start();

	this->_logger->info("Started RakLib...");
}

void Server::stop() {
	this->_logger->info("Stopping server..");

	this->_scheduler->stop();
	this->_raklib->stop();

	this->_logger->info("Stopped RakLib");
}

void Server::addSession(const std::string& ip, uint16 port, int64 clientID, int16 mtu) {
	this->_logger->notice("New player have connected - %s:%d", ip.c_str(), port);
	this->_players[this->_raklib->getSessionIdentifier(ip, port)] = new Player(this, ip, port, clientID, mtu);
}

bool Server::removeSession(const std::string& ip, unsigned short port) {
	if (this->_players[this->_raklib->getSessionIdentifier(ip, port)] == nullptr) {
		return false;
	}

	//The session should delete his resource
	delete this->_players[this->_raklib->getSessionIdentifier(ip, port)];
	return true;
}

RakLib::Session* Server::getSession(const std::string& ip, unsigned short port) {
	return this->_players[this->_raklib->getSessionIdentifier(ip, port)];
}

int64 Server::getIdentifier() {
	return 123456789LL;
}

bool Server::useSecurity() {
	return false;
}

const std::string Server::getType() {
	return "MCPE";
}

const std::string Server::getName() {
	return "Minecraft Server!";
}

int32 Server::getProtocol() {
	return 105;
}

const std::string Server::getGameVersion() {
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
