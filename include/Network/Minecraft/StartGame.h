#ifndef STARTGAME_H_
#define STARTGAME_H_

#include <RakLib\Packets\DataPacket.h>

class StartGame : public RakLib::DataPacket
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

	void encode() override;
};
#endif // !STARTGAME_H_
