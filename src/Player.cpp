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

#include "Player.h"
#include "Server.h"
#include "Network\Minecraft\ClientConnect.h"
#include "Network\Minecraft\Login.h"
#include "Network\Minecraft\MinecraftPackets.h"
#include "Network\Minecraft\Ping.h"
#include "Network\Minecraft\Pong.h"
#include "Network\Minecraft\ServerHandshake.h"
#include "Scheduler\CallbackTask.h"

Player::Player(Server* server, std::string ip, uint16 port, long clientID, short mtuSize) : RakLib::Session(ip, port, clientID, mtuSize) {
	this->_server = server;
	this->_username = "Steve";

	this->_server->getScheduler()->addTask(new CallbackTask(std::function<void()>(std::bind(&Player::update, this)), 10, -1));
}

Player::~Player() {
	//No resource to release
}

void Player::close(std::string reason) {
	//TODO
}

//The `DataPacket` get deleted in the Session:receivePacket() method
void Player::handleDataPacket(RakLib::DataPacket* packet) {
	uint8 packetID = (*packet)[0];

	this->_server->getLogger()->debug("Packet ID: %02X", packetID);

	switch (packetID) {
	case MinecraftPackets::PING:
	{
		Ping ping(packet);
		ping.decode();


		Pong pong(ping.pingID);
		pong.encode();
		this->addToQueue(&pong, RakLib::Session::QueuePriority::IMMEDIATE);
	}
	break;

	case MinecraftPackets::CLIENT_CONNECT:
	{
		ClientConnect clientConnect(packet);
		clientConnect.decode();

		ServerHandshake serverHandshake(this->_ip, this->_port, clientConnect.sendPing, clientConnect.sendPing * 1000L);
		serverHandshake.encode();
		this->addToQueue(&serverHandshake, RakLib::Session::QueuePriority::IMMEDIATE);
	}
	break;

	case MinecraftPackets::LOGIN_PACKET:
	{
		Login login(packet);
		login.decode();

		if (login.protocol != NETWORK_PROTOCOL || login.protocol2 != NETWORK_PROTOCOL){
			if (login.protocol < NETWORK_PROTOCOL || login.protocol2 < NETWORK_PROTOCOL){
				//this->addToQueue(new LoginStatus(1)); // Client outdated
				//close("Wrong Protocol: Client is outdated.");
			}
			if (login.protocol > NETWORK_PROTOCOL || login.protocol2 > NETWORK_PROTOCOL){
				//addPacketToQueue(new LoginStatus(2)); // Server outdated
				//close("Wrong Protocol: Server is outdated.");
			}
		}

		this->_server->getLogger()->debug("%s (%s:%d) have joined...", login.username.c_str(), this->_ip.c_str(), this->_port);

		
	}
	break;

	}
}

void Player::sendPacket(RakLib::Packet* packet) {
	this->_server->sendPacket(packet);
}


const std::string Player::getLUsername() {
	//We should do this every time? or store the result as a member?
	std::string lname = this->_username.c_str();
	std::transform(lname.begin(), lname.end(), lname.begin(), ::tolower);
	return lname;
}