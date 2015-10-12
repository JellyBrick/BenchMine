/**
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* @author InusualZ
*
*
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <map>

#include <RakLib\RakLib.h>

#include "Logger\ColoredLogger.h"

class Player;
class Server : public RakLib::SessionManager
{

private:
	RakLib::RakLib* _raklib;
	ColoredLogger* _logger;

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

	bool addSession(std::string ip, unsigned short port, long clientID, unsigned short mtu);
	bool removeSession(std::string ip, unsigned short port);
	RakLib::Session* getSession(std::string ip, unsigned short port);

	inline void sendPacket(RakLib::Packet* packet) { this->_raklib->sendPacket(packet); };

	inline ColoredLogger* getLogger() const { return this->_logger; }

	inline uint16 getPort() const { return this->_port; }; // Server Ports
	inline uint32 getMaxPlayers() const { return this->_maxPlayers; }; // Server Max Players
	inline const std::string& getIP() const { return this->_ip; }; // Server IP
	inline const std::string& getMOTD() const { return this->_motd; }; // Message of the day.
	inline const std::string& getTitle() const { return this->_title; }; // Server Title

};
#endif
