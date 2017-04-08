#pragma once

#include <map>
#include <memory>

#include <RakLib.h>
#include <SessionManager.h>

#include "logger/ColoredLogger.h"
#include "scheduler/TaskHandler.h"
#include "world/level/Level.h"

class NetworkSession;
class Server final : public RakLib::SessionManager {
private:
	static constexpr unsigned int MINECRAFT_TICK_RATE = 20;

	std::unique_ptr<RakLib::RakLib> raklib;
	std::unique_ptr<ColoredLogger> logger;
	std::unique_ptr<TaskHandler> scheduler;
	std::unique_ptr<Level> level;

	uint16 port;
	uint32 maxPlayers;
	std::string  ip;
	std::string motd;
	std::string title;
	std::map<std::string, std::unique_ptr<NetworkSession>> playerSessions;

	uint32 networkTick;

public:
	Server();
	virtual ~Server();

	void start();
	void stop();

	void addSession(const std::string& sessionIP, uint16 sessionPort, int64 clientID, int16 mtu) override;
	void removeSession(const std::string& sessionIP, uint16 sessionPort) override;
	RakLib::Session* getSession(const std::string& sessionIP, uint16 sessionPort) override;

	void sendPacket(const RakLib::Packet& packet) const { raklib->sendPacket(packet); }

	void update();

	int64 getIdentifier() override;
	bool useSecurity() override;
	std::string getType() override;
	std::string getName() override;
	int32 getProtocol() override;
	std::string getGameVersion() override;
	uint32 getActivePlayers() override;
	uint32 getMaxPlayer() override;

	ColoredLogger* getLogger() const { return logger.get(); }
	TaskHandler* getScheduler() const { return scheduler.get(); }

	Level* getLevel() const { return level.get(); }

	uint16 getPort() const { return port; }; // Server Ports
	const std::string& getIP() const { return ip; }; // Server IP

private:
	std::string getSessionID(const std::string& sessionIP, uint16 port);
};