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

#include "PlayerManager.h"

#include "Network/Minecraft/MinecraftPackets.h"
#include "Network/Minecraft/Acknowledge.h"
#include "Network/Raknet/LoginPackets.h"
#include "Network/Raknet/UnConnectedPing.h"
#include "Network/Raknet/UnConnectedPong.h"
#include "Network/Raknet/Request1.h"
#include "Network/Raknet/Request2.h"
#include "Network/Raknet/Reply1.h"
#include "Network/Raknet/Reply2.h"

PlayerManager::PlayerManager(int maxPlayer)
{
	this->maxPlayers = maxPlayer;
	this->socketHandler = new SocketHandler(Server::getInstance()->getIP(), Server::getInstance()->getPort());
}

void PlayerManager::Start()
{
	this->socketHandler->Start();
}

void PlayerManager::Stop()
{
	if (!this->socketHandler->Running())
	{
		throw std::runtime_error("SocketHandler thread is not running!");
	}
	this->socketHandler->Stop();
}

void PlayerManager::sendPacket(Packet* packet)
{
	this->socketHandler->SendPacket(packet);
}

void PlayerManager::handlePacket(Packet* pck)
{
	uint8_t pid = pck->getBuffer()[0];
	if (pid >= LoginPackets::UNCONNECTED_PONG && pid <= LoginPackets::CONNECTION_REPLY_2)
	{
		switch (pid)
		{
		case LoginPackets::UNCONNECTED_PONG:
		case LoginPackets::UNCONNECTED_PONG_2:
		{
			UnConnectedPing* ping = new UnConnectedPing(pck);
			ping->decode();


			UnConnectedPong* pong = new UnConnectedPong(123456789, ping->pingID, Server::getInstance()->getTitle());
			pong->encode();

			pong->ip = pck->ip;
			pong->port = pck->port;

			this->socketHandler->SendPacket(pong); // Send the packet

			delete ping;
			delete pong;
		}
		break;

		case LoginPackets::CONNECTION_REQUEST_1:
		{
			Request1* request = new Request1(pck);
			request->decode();

			Reply1* reply = new Reply1(0x00, 123456789, request->mtuSize);
			reply->encode();

			reply->ip = pck->ip;
			reply->port = pck->port;

			this->socketHandler->SendPacket(reply); // Send the packet

			delete request;
			delete reply;
		}
		break;

		case LoginPackets::CONNECTION_REQUEST_2:
		{
			Request2* request = new Request2(pck);
			request->decode();

			Reply2* reply = new Reply2(123456789L, pck->port, request->mtuSize, request->Security);
			reply->encode();

			reply->ip = pck->ip;
			reply->port = pck->port;

			this->socketHandler->SendPacket(reply); // Send the packet

			this->players[this->getPlayerIdentifier(pck->ip, pck->port)] = new Player(pck->ip, pck->port, request->clientID, reply->mtuSize);
			
			delete reply;
			delete request;
		}
		break;

		default:
			throw std::runtime_error("Unknown Packet ID");
			break;
		}
	}
	else if (pid >= 0x80 && pid <= 0x8f)
	{
		this->players[this->getPlayerIdentifier(pck->ip, pck->port)]->handlePacket(new CustomPacket(pck));

	}
	else if (pid == 0xA0 || pid == 0xC0)
	{
		//TODO: Player Handle the ACK and NACK
		//Acknowledge* acknowledge = new Acknowledge(pck);
		//acknowledge->decode();
	}

	delete pck;
}

std::string PlayerManager::getPlayerIdentifier(std::string ip, uint16_t port)
{
	return ip.append(":" + port);
}