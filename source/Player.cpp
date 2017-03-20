#include "Player.h"

#include <algorithm>

#include "Server.h"
#include "scheduler/CallbackTask.h"
#include "network/minecraft/ClientConnect.h"
#include "network/minecraft/Login.h"
#include "network/minecraft/MinecraftPackets.h"
#include "network/minecraft/Ping.h"
#include "network/minecraft/Pong.h"
#include "network/minecraft/ServerHandshake.h"

Player::Player(Server* server, std::string ip, uint16 port, int64 clientID, int16 mtuSize) : RakLib::Session(ip, port, clientID, mtuSize) {
	this->server = server;
	this->username = "Steve";

	this->server->getScheduler()->addTask(new CallbackTask(std::function<void()>(std::bind(&Player::update, this)), 10, -1));
}

Player::~Player() {
	//No resource to release
}

void Player::close(const std::string& reason) {
	//TODO
}

//The `DataPacket` get deleted in the Session:receivePacket() method
void Player::handleDataPacket(RakLib::DataPacket* packet) {
	uint8 packetID = (*packet)[0];
	this->server->getLogger()->debug("Packet ID: %02X", packetID);

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

		ServerHandshake serverHandshake(this->ip, this->port, clientConnect.sendPing, (int64)(clientConnect.sendPing * 1000LL));
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

		this->server->getLogger()->debug("%s (%s:%d) have joined...", login.username.c_str(), this->ip.c_str(), this->port);
	}
	break;

	}
}

void Player::sendPacket(RakLib::Packet* packet) {
	this->server->sendPacket(packet);
}

const std::string Player::getLUsername() {
	//We should do this every time? or store the result as a member?
	std::string lname = this->username;
	std::transform(lname.begin(), lname.end(), lname.begin(), ::tolower);
	return lname;
}