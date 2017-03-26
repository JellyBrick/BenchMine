#include "MinecraftPackets.h"
#include "StartGame.h"

StartGame::StartGame(float x, float y, float z, int gamemode, int seed, int eid) : DataPacket(29) {
	this->spawnX = x;
	this->spawnY = y;
	this->spawnZ = z;
	this->gamemode = gamemode;
	this->seed = seed;
	this->eid = eid;
	this->unknown = 0;
}

void StartGame::encode() {
	this->putByte(MinecraftPackets::START_GAME);
	this->putInt(seed);
	this->putInt(unknown);
	this->putInt(gamemode);
	this->putInt(eid);
	this->putFloat(spawnX);
	this->putFloat(spawnY);
	this->putFloat(spawnZ);
}
