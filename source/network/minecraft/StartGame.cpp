#include "StartGame.h"

#include "MinecraftPackets.h"

StartGame::StartGame(uint64 EID, const Vector3f& spawnPoint, const std::string& world) : DataPacket(89 + world.length()) {
	setEndianness(Endianness::LITTLE);
	entityId = runtimeEntityId = EID;
	spawn = spawnPoint;
	seed = 123456789;
	dimension = 0;
	generator = 2;
	gamemode = 1;
	difficulty = 1;
	playerPosition = Vector3i::fromVector3f(spawnPoint);
	hasAchievementsDisabled = true;
	dayCycleStopTime = 6400;
	eduMode = false;
	rainLevel = 0;
	lightnigLevel = 0;
	enableCommands = true;
	isTexturepacksRequired = false;
	worldName = world;
}

void StartGame::encode() {
	putByte(static_cast<uint8>(MinecraftPackets::StartGame));
	putVarULong(entityId);
	putVarULong(runtimeEntityId);
	Vector3f::serialize(spawn, *this);
	Vector2f::serialize(unknown1, *this);
	putVarUInt(seed);
	putVarUInt(dimension);
	putVarUInt(generator);
	putVarUInt(gamemode);
	putVarUInt(difficulty);
	Vector3i::serialize(playerPosition, *this);
	putBool(hasAchievementsDisabled);
	putVarUInt(static_cast<uint32>(dayCycleStopTime));
	putBool(eduMode);
	putFloat(rainLevel);
	putFloat(lightnigLevel);
	putBool(enableCommands);
	putBool(isTexturepacksRequired);
	putVarString(secret);
	putVarString(worldName);
}