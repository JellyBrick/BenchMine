#pragma once

#include "Common.h"

static constexpr int NETWORK_PROTOCOL = 105;
static constexpr const char* GAME_VERSION = "1.0.5";

enum class MinecraftPackets : uint8 {
	Login = 0x01,	
	PlayStatus = 0x02,
	ServerHandshake = 0x03,
	ClientHandshake = 0x04,
	Disconnect = 0x05,
	Batch = 0x06,
	ResourcePacksInfo = 0x07,
	ResourcePackStack = 0x08,
	ResourcePackClientResponse = 0x09,
	Text = 0x0a,
	SetTime = 0x0b,
	StartGame = 0x0c,
	AddPlayer = 0x0d,
	AddEntity = 0x0e,
	RemoveEntity = 0x0f,
	AddItemEntity = 0x10,
	AddHangingEntity = 0x11,
	TakeItemEntity = 0x12,
	MoveEntity = 0x13,
	MovePlayer = 0x14,
	RiderJump = 0x15,
	RemoveBlock = 0x16,
	UpdateBlock = 0x17,
	AddPainting = 0x18,
	Explode = 0x19,
	LevelSoundEvent = 0x1a,
	LevelEvent = 0x1b,
	BlockEvent = 0x1c,
	EntityEvent = 0x1d,
	MobEffect = 0x1e,
	UpdateAttributes = 0x1f,
	MobEquipment = 0x20,
	MobArmorEquipment = 0x21,
	Interact = 0x22,
	BlockPickRequest = 0x23,
	UseItem = 0x24,
	PlayerAction = 0x25,
	PlayerFall = 0x26,
	HurtArmor = 0x27,
	SetEntityData = 0x28,
	SetEntityMotion = 0x29,
	SetEntityLink = 0x2a,
	SetHealth = 0x2b,
	SetSpawnPosition = 0x2c,
	Animate = 0x2d,
	Respawn = 0x2e,
	DropItem = 0x2f,
	InventoryAction = 0x30,
	ContainerOpen = 0x31,
	ContainerClose = 0x32,
	ContainerSetSlot = 0x33,
	ContainerSetData = 0x34,
	ContainerSetContent = 0x35,
	CraftingData = 0x36,
	CraftingEvent = 0x37,
	AdventureSettings = 0x38,
	BlockEntityData = 0x39,
	PlayerInput = 0x3a,
	FullChunkData = 0x3b,
	SetCommandsEnabled = 0x3c,
	SetDifficulty = 0x3d,
	ChangeDimension = 0x3e,
	SetPlayerGameType = 0x3f,
	PlayerList = 0x40,
	Event = 0x41,
	SpawnExperienceOrb = 0x42,
	ClientboundMapItemData = 0x43,
	MapInfoRequest = 0x44,
	RequestChunkRadius = 0x45,
	ChunkRadiusUpdate = 0x46,
	ItemFrameDropItem = 0x47,
	ReplaceSelectedItem = 0x48,
	GameRulesChanged = 0x49,
	Camera = 0x4a,
	AddItem = 0x4b,
	BossEvent = 0x4c,	
	ShowCredits = 0x4d,
	AvailableCommands = 0x4e,
	CommandStep = 0x4f,
	CommandBlockUpdate = 0x50,
	UpdateTrade = 0x51,
	ResourcePackDataInfo = 0x52,
	ResourcePackChunkData = 0x53,
	ResourcePackChunkRequest = 0x54,
	Transfer = 0x55,
	PlaySound = 0x56,
	StopSound = 0x57,
	SetTitle = 0x58
};