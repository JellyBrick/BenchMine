#include "Server.h"

#include "common/Utils.h"
#include "network/minecraft/MinecraftPackets.h"
#include "scheduler/CallbackTask.h"
#include "world/entity/player/NetworkSession.h"

#include <fstream>
#include <iostream>

#include <INIReader.h>

const unsigned int Server::MINECRAFT_TICK_RATE = 20;

Server::Server() {
	INIReader reader("server.ini");

	if (reader.ParseError() < 0) {
		std::ofstream serverINI("server.ini");
		serverINI << "[normalSettings]\n"
			<< "maxPlayers=20\n"
			<< "ip=0.0.0.0\n"
			<< "port=19132\n"
			<< "motd=Welcome to the BenchMine Server!\n"
			<< "title=BenchMine Minecraft Server!\n";
		serverINI.close();
		std::cout << "Can't load 'server.ini'\n";
	}

	maxPlayers = reader.GetInteger("normalSettings", "maxPlayers", 20);
	ip = reader.Get("normalSettings", "ip", "0.0.0.0");
	port = reader.GetInteger("normalSettings", "port", 19132);
	motd = reader.Get("normalSettings", "motd", "Welcome to the BenchMine Server!");
	title = reader.Get("normalSettings", "title", "BenchMine Minecraft Server!");
	raklib = std::make_unique<RakLib::RakLib>(this, ip, port);
	logger = std::make_unique<ColoredLogger>();
	scheduler = std::make_unique<TaskHandler>(MINECRAFT_TICK_RATE);
	level = std::make_unique<Level>(2);

	Utils::setConsoleTitle("BenchMine Server Software");
	logger->info("BenchMine Server Software under LGPL v3");
	scheduler->addTask(new CallbackTask(std::function<void()>(std::bind(&Server::update, this)), 1, -1));
}

void Server::start() {
	logger->info("Server at %s:%u - %s", ip.c_str(), port, title.c_str());

	scheduler->start();
	raklib->start();

	logger->info("Started RakLib...");
}

void Server::stop() {
	logger->info("Stopping server..");

	for (const auto& it : playerSessions) {
		it.second->disconnect("Server Closing!");
	}

	playerSessions.clear();

	scheduler->stop();
	raklib->stop();

	logger->info("Stopped RakLib");
}

void Server::addSession(const std::string& sessionIP, uint16 sessionPort, int64 clientID, int16 mtu) {
	if (getSession(sessionIP, sessionPort) != nullptr) {
		return;
	}

	playerSessions[getSessionID(sessionIP, sessionPort)] = std::make_unique<NetworkSession>(this, sessionIP, sessionPort, clientID, mtu);
}

void Server::removeSession(const std::string& sessionIP, uint16 sessionPort) {
	if (getSession(sessionIP, sessionPort) == nullptr) {
		return;
	}

	delete getSession(sessionIP, sessionPort);
}

RakLib::Session* Server::getSession(const std::string& sessionIP, uint16 sessionPort) {
	return playerSessions[getSessionID(sessionIP, sessionPort)].get();
}

std::string Server::getSessionID(const std::string& sessionIP, uint16 sessionPort) {
	return sessionIP + (":" + sessionPort);
}

void Server::update() {
	networkTick = networkTick++ % 5;
	if (networkTick == 5) {
		for (const auto& session : playerSessions) {
			session.second->update();
		}
	}

	level->update();
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
	return playerSessions.size();
}

uint32 Server::getMaxPlayer() {
	return maxPlayers;
}

Server::~Server() {
	stop();
}
