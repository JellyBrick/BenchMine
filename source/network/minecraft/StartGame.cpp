#include "StartGame.h"

#include "MinecraftPackets.h"

StartGame::StartGame(int64 EID, const Vector3f& spawnPoint, const std::string& world) : DataPacket(89 + world.length()) {
	this->entityId = this->runtimeEntityId = EID;
	this->spawn = spawnPoint;
	this->seed = 123456789;
	this->dimension = 0;
	this->generator = 2;
	this->gamemode = 1;
	this->difficulty = 1;
	this->playerPosition = Vector3i::fromVector3f(spawnPoint);
	this->hasAchievementsDisabled = true;
	this->dayCycleStopTime = 6400;
	this->eduMode = false;
	this->rainLevel = 0;
	this->lightnigLevel = 0;
	this->enableCommands = true;
	this->isTexturepacksRequired = false;
	this->worldName = world;
}

void StartGame::encode() {
	this->putByte((uint8)MinecraftPackets::START_GAME);
	this->putVarULong(this->entityId);
	this->putVarULong(this->runtimeEntityId);
	Vector3f::serialize(this->spawn, *this);
	Vector2f::serialize(this->unknown1, *this);
	this->putVarUInt(this->seed);
	this->putVarUInt(this->dimension);
	this->putVarUInt(this->generator);
	this->putVarUInt(this->gamemode);
	this->putVarUInt(this->difficulty);
	Vector3i::serialize(this->playerPosition, *this);
	this->putBool(this->hasAchievementsDisabled);
	this->putVarUInt((uint32)this->dayCycleStopTime);
	this->putBool(this->eduMode);
	this->putFloat(this->rainLevel);
	this->putFloat(this->lightnigLevel);
	this->putBool(enableCommands);
	this->putBool(isTexturepacksRequired);
	this->putString(this->secret);
	this->putString(this->worldName);
}
