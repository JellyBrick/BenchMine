#pragma once

#include <string>

static constexpr int NETWORK_PROTOCOL = 102;
static constexpr const char* GAME_VERSION = "1.0.5";

enum MinecraftPackets : unsigned char {
	LOGIN = 0x01,
	PLAY_STATUS = 0x02,
	SERVER_HANDSHAKE = 0x03,
	CLIENT_HANDSHAKE = 0x04,
	DISCONNECT = 0x05,
	BATCH = 0x06,
	RESOURCE_PACKS_INFO = 0x07,
	RESOURCE_PACKS_STACK = 0x08,
	RESOURCE_PACK_CLIENT_RESPONSE = 0x09,
	TEXT = 0x0a,
	SET_TIME = 0x0b,
	START_GAME = 0x0c,
	ADD_PLAYER = 0x0d,
	ADD_ENTITY = 0x0e,
	REMOVE_ENTITY = 0x0f,
	ADD_ITEM_ENTITY = 0x10,
	ADD_HANGING_ENTITY = 0x11,
	TAKE_ITEM_ENTITY = 0x12,
	MOVE_ENTITY = 0x13,
	MOVE_PLAYER = 0x14,
	RIDER_JUMP = 0x15,
	REMOVE_BLOCK = 0x16,
	UPDATE_BLOCK = 0x17,
	ADD_PAINTING = 0x18,
	EXPLODE = 0x19,
	LEVEL_SOUND_EVENT = 0x1a,
	LEVEL_EVENT = 0x1b,
	BLOCK_EVENT = 0x1c,
	ENTITY_EVENT = 0x1d,
	MOB_EFFECT = 0x1e,
	UPDATE_ATTRIBUTES = 0x1f,
	MOB_EQUIPMENT = 0x20,
	MOB_ARMOR_EQUIPMENT = 0x21,
	INTERACT = 0x22,
	USE_ITEM = 0x23,
	PLAYER_ACTION = 0x24,
	PLAYER_FALL = 0x25,
	HURT_ARMOR = 0x26,
	SET_ENTITY_DATA = 0x27,
	SET_ENTITY_MOTION = 0x28,
	SET_ENTITY_LINK = 0x29,
	SET_HEALTH = 0x2a,
	SET_SPAWN_POSITION = 0x2b,
	ANIMATE = 0x2c,
	RESPAWN = 0x2d,
	DROP_ITEM = 0x2e,
	INVENTORY_ACTION = 0x2f,
	CONTAINER_OPEN = 0x30,
	CONTAINER_CLOSE = 0x31,
	CONTAINER_SET_SLOT = 0x32,
	CONTAINER_SET_DATA = 0x33,
	CONTAINER_SET_CONTENT = 0x34,
	CRAFTING_DATA = 0x35,
	CRAFTING_EVENT = 0x36,
	ADVENTURE_SETTINGS = 0x37,
	BLOCK_ENTITY_DATA = 0x38,
	PLAYER_INPUT = 0x39,
	FULL_CHUNK_DATA = 0x3a,
	SET_COMMANDS_ENABLED = 0x3b,
	SET_DIFFICULTY = 0x3c,
	CHANGE_DIMENSION = 0x3d,
	SET_PLAYER_GAME_TYPE = 0x3e,
	PLAYER_LIST = 0x3f,
	EVENT = 0x40, //TelemetryEventPacket
	SPAWN_EXPERIENCE_ORB = 0x41,
	CLIENTBOUND_MAP_ITEM_DATA = 0x42, //MapItemDataPacket
	MAP_INFO_REQUEST = 0x43,
	REQUEST_CHUNK_RADIUS = 0x44,
	CHUNK_RADIUS_UPDATED = 0x45,
	ITEM_FRAME_DROP_ITEM = 0x46,
	REPLACE_SELECTED_ITEM = 0x47, //ReplaceSelectedItemPacket
	GAME_RULES_CHANGED = 0x48,
	CAMERA = 0x49,
	ADD_ITEM = 0x4a,
	BOSS_EVENT = 0x4b,
	SHOW_CREDITS = 0x4c,
	AVAILABLE_COMMANDS = 0x4d,
	COMMAND_STEP = 0x4e,
	UPDATE_TRADE = 0x4f,
	RESOURCE_PACK_DATA_INFO = 0x50,
	RESOURCE_PACK_CHUNK_DATA = 0x51,
	RESOURCE_PACK_CHUNK_REQUEST = 0x52,
	TRANSFER = 0x53,
};