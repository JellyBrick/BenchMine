#include "StartGame.h"

#include "MinecraftPackets.h"
#include "network/raknet/RaknetPackets.h"

StartGame::StartGame(int64 EID, const Vector3f& spawnPoint, const std::string& world) : DataPacket(512) {
	this->entityId = this->runtimeEntityId = EID;
	this->spawn = spawnPoint;
	this->seed = 123456789;
	this->dimension = 0;
	this->generator = 2;
	this->gamemode = 1;
	this->difficulty = 1;
	this->playerPosition = Vector3i::fromVector3f(spawnPoint);
	this->hasAchievementsDisabled = true;
	this->dayCycleStopTime = -1;
	this->eduMode = false;
	this->rainLevel = 0;
	this->lightnigLevel = 0;
	this->enableCommands = true;
	this->isTexturepacksRequired = false;
	this->worldName = world;
}

void StartGame::encode() {
	this->putByte((uint8)RaknetPacket::WRAPPER);
	this->putByte((uint8)MinecraftPackets::START_GAME);
	this->putLong(this->entityId);
	this->putULong(this->runtimeEntityId);
	Vector3f::serialize(this->spawn, *this);
	Vector2f::serialize(this->unknown1, *this);
	this->putInt(this->seed);
	this->putInt(this->dimension);
	this->putInt(this->generator);
	this->putInt(this->gamemode);
	this->putInt(this->difficulty);
	Vector3i::serialize(this->playerPosition, *this);
	this->putBool(this->hasAchievementsDisabled);
	this->putInt(this->dayCycleStopTime);
	this->putBool(this->eduMode);
	this->putInt(this->rainLevel);
	this->putInt(this->lightnigLevel);
	this->putBool(enableCommands);
	this->putBool(isTexturepacksRequired);
	this->putString(this->secret);
	this->putString(this->worldName);

	printf("%u\n", this->position);
}
