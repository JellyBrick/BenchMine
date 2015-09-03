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

Player::Player(std::string ip, uint16_t port, long clientID, short mtuSize)
{
	this->username = "Steve";
	this->ip = ip;
	this->port = port;
	this->clientID = clientID;
	this->lastSequenceNum = 0;
	this->sequenceNum = 0;
	this->messageIndex = 0;
	this->CID = (int) clientID;
	this->mtuSize = mtuSize;
	this->server = Server::getInstance();
	this->queue = new CustomPacket();

	//this->server.getScheduler().addTask(new CallbackTask(this, "update", 10, true));
}


std::string Player::getUsername()
{
	return this->username;
}

std::string Player::getLUsername()
{
	std::string lname = this->username.c_str();
	std::transform(lname.begin(), lname.end(), lname.begin(), ::tolower);
	return lname;

}


void Player::addToQueue(DataPacket* pck)
{
	InternalPacket* ipck = new InternalPacket();
	ipck->buff = pck->getBuffer();
	ipck->reliability = 2;
	ipck->messageIndex = messageIndex++;
	ipck->toBinary();
	if (queue->getLength() >= 1){
		queue->sequenceNumber = sequenceNum++;
		queue->encode();
		this->server->getPlayerManager()->sendPacket(queue);
		
		queue->packets.clear();
		return;
	}
	queue->packets.push_back(ipck);
}


void Player::handlePacket(CustomPacket* customPacket)
{
	customPacket->decode();
	this->ACKQueue.push_back(customPacket->sequenceNumber);

	if (customPacket->sequenceNumber - this->lastSequenceNum > 1)
	{
		for (int i = this->lastSequenceNum; i < customPacket->sequenceNumber; ++i)
		{
			this->NACKQueue.push_back(i);
		}
	}
	this->lastSequenceNum = customPacket->sequenceNumber;

	for (InternalPacket* packet : customPacket->packets)
	{
		uint8_t pid = packet->buff[0];
		printf("Packet Received: %02X", pid);
		switch (pid)
		{

		case MinecraftPackets::PING: //PING Packet
		{
			Ping* pp = new Ping(packet);
			pp->decode();
			Pong* reply = new Pong(pp->pingID);
			reply->encode();
			this->addToQueue(reply);
		}
		break;

		case MinecraftPackets::CLIENT_CONNECT: // 0x09. Use the constants class
		{
			ClientConnect* ccp = new ClientConnect(packet);
			ccp->decode();
			//Send a ServerHandshake packet
			ServerHandshake* shp = new ServerHandshake(this->port, ccp->session);
			shp->encode();
			this->addToQueue(shp);
		}
		break;

		case MinecraftPackets::LOGIN_PACKET:
		{
			Login* lp = new Login(packet);
			lp->decode();
			if (lp->protocol != MinecraftPackets::CURRENT_PROTOCOL || lp->protocol2 != MinecraftPackets::CURRENT_PROTOCOL){
				if (lp->protocol < MinecraftPackets::CURRENT_PROTOCOL || lp->protocol2 < MinecraftPackets::CURRENT_PROTOCOL){
					LoginStatus* ls = new LoginStatus(1);
					ls->encode();
					this->addToQueue(ls); // Client outdated
					this->close("Wrong Protocol: Client is outdated.");
				}

				if (lp->protocol > MinecraftPackets::CURRENT_PROTOCOL || lp->protocol2 > MinecraftPackets::CURRENT_PROTOCOL){
					LoginStatus* ls = new LoginStatus(2);
					ls->encode();
					this->addToQueue(ls); // Client outdated
					this->close("Wrong Protocol: Server is outdated.");
				}
			}
			LoginStatus* ls = new LoginStatus(0);
			ls->encode();
			this->addToQueue(ls); // Client outdated
			if (lp->username.length() < 3 || lp->username.length() > 15){
				this->close("Username is not valid.");
			}
			else{
				this->username = lp->username;

				StartGame* sgp = new StartGame(0, 0, 0, 1, 100, 0);
				sgp->encode();
				this->addToQueue(sgp);
			}
		}
		break;

		default:
		{
			printf("Unsupported packet received: %02X", packet->buff[0]);
		}
		break;

		}
	}
	delete customPacket;
}

void Player::handlePacket(Acknowledge* acknowledge)
{}

void Player::close(std::string reason)
{}