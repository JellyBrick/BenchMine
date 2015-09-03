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

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Network/Minecraft/CustomPacket.h"
#include "Network/Minecraft/DataPacket.h"
#include "Network/Minecraft/Acknowledge.h"
#include "Network/Minecraft/ClientConnect.h"
#include "Network/Minecraft/ServerHandshake.h"
#include "Network/Minecraft/Login.h"
#include "Network/Minecraft/LoginStatus.h"
#include "Network/Minecraft/StartGame.h"
#include "Network/Minecraft/Ping.h"
#include "Network/Minecraft/Pong.h"
#include "Entity/Entity.h"
#include "Server.h"
#include "PlayerManager.h"

class Server;
class PlayerManager;
class Player : public Entity
{
private:
	std::string username;
	std::string ip;

	int port;
	int CID;
	int lastSequenceNum;
	int sequenceNum;
	int messageIndex;

	long clientID;

	short mtuSize;

	Server* server;
	CustomPacket* queue;
	std::vector<int> ACKQueue; // Received Packet Queue
	std::vector<int> NACKQueue; // Not received packet queue
	std::map<int, CustomPacket> recoveryQueue; // Packet sent queue to be used if not received

public:
	Player(std::string ip, uint16_t port, long clientID, short mtuSize);
	~Player();

	std::string getUsername();
	std::string getLUsername();

	void addToQueue(DataPacket* pck);

	void handlePacket(CustomPacket* customPacket);
	void handlePacket(Acknowledge* acknowledge);

	void close(std::string reason);
};
#endif