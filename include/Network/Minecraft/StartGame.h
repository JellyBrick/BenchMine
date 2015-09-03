#ifndef STARTGAME_H_
#define STARTGAME_H_

#include "DataPacket.h"

class StartGame : public DataPacket
{
public:
	int seed;
	int unknown;
	int gamemode;
	int eid;
	float spawnX;
	float spawnY;
	float spawnZ;

public:
	StartGame(float x, float y, float z, int gamemode, int seed, int eid);

	void encode();
	void decode();
};
#endif // !STARTGAME_H_
