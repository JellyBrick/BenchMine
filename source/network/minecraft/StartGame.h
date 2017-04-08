#pragma once

#include <string>

#include <RakLib/protocol/DataPacket.h>

#include "world/math/Vector2f.h"
#include "world/math/Vector3f.h"
#include "world/math/Vector3i.h"

class StartGame : public RakLib::DataPacket {
public:
	uint64 entityId;
	uint64 runtimeEntityId;
	Vector3f spawn;
	Vector2f unknown1;
	uint32 seed;
	uint32 dimension;
	uint32 generator;
	uint32 gamemode; 
	uint32 difficulty;
	Vector3i playerPosition;
	bool hasAchievementsDisabled;
	int32 dayCycleStopTime;
	bool eduMode;
	f32 rainLevel;
	f32 lightnigLevel;
	bool enableCommands;
	bool isTexturepacksRequired;
	std::string secret;
	std::string worldName;

public:
	StartGame(uint64 EID, const Vector3f& spawnPoint, const std::string& world);
	void encode() override;
};
