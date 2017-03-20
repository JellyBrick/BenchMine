#pragma once

#include <map>

#include <RakLib.h>
#include <SessionManager.h>

#include "logger\ColoredLogger.h"
#include "scheduler\TaskHandler.h"

class Player;
class Server : public RakLib::SessionManager {
private:
	RakLib::RakLib* _raklib;
	ColoredLogger* _logger;
	TaskHandler* _scheduler;

	uint16 _port;
	uint32 _maxPlayers;
	std::string  _ip;
	std::string _motd;
	std::string _title;
	std::map<std::string, Player*> _players;

public:
	Server();
	~Server();

	void start();
	void stop();

	virtual void addSession(const std::string& ip, uint16 port, int64 clientID, int16 mtu);
	virtual bool removeSession(const std::string& ip, unsigned short port);
	virtual RakLib::Session* getSession(const std::string& ip, unsigned short port);

	virtual int64 getIdentifier();
	virtual bool useSecurity();
	virtual const std::string getType();
	virtual const std::string getName();
	virtual int32 getProtocol();
	virtual const std::string getGameVersion();
	virtual uint32 getActivePlayers();
	virtual uint32 getMaxPlayer();

	inline void sendPacket(RakLib::Packet* packet) { this->_raklib->sendPacket(packet); };

	inline ColoredLogger* getLogger() const { return this->_logger; }
	inline TaskHandler* getScheduler() const { return this->_scheduler; }

	inline uint16 getPort() const { return this->_port; }; // Server Ports
	inline const std::string& getIP() const { return this->_ip; }; // Server IP
};
