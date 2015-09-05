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

#include <iostream>
#include <RakLib\RakLib.h>

class Player;
class Server : public RakLib::SessionManager
{

private:
	RakLib::RakLib* _raklib;


	uint16 _port;
	uint32 _maxPlayers;
	std::string  _ip;
	std::string _motd;
	std::string _title;

public:
	Server();
	~Server();

	void start();
	void stop();

	bool addSession(std::string ip, unsigned short port, long clientID, unsigned short mtu);
	bool removeSession(std::string ip, unsigned short port);
	RakLib::Session* getSession(std::string ip, unsigned short port);

	inline void sendPacket(RakLib::Packet* packet) { this->_raklib->sendPacket(packet); };

	inline uint16 getPort() const { this->_port; }; // Server Ports
	inline uint32 getMaxPlayers() const { this->_maxPlayers; }; // Server Max Players
	inline const std::string& getIP() const { this->_ip; }; // Server IP
	inline const std::string& getMOTD() const { this->_motd; }; // Message of the day.
	inline const std::string& getTitle() const { this->_title; }; // Server Title

};
#endif
