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
#ifndef MINECRAFT_PACKETS_H_
#define MINECRAFT_PACKETS_H_

enum MinecraftPackets
{
	CURRENT_PROTOCOL = 20,

	PING = 0x00,
	PONG = 0x03,

	CLIENT_CONNECT = 0x09,
	SERVER_HANDSHAKE = 0x10,

	CLIENT_HANDSHAKE = 0x13,

	SERVER_FULL = 0x14,
	DISCONNECT = 0x15,

	BANNED = 0x17,

	LOGIN_PACKET = 0x82,
	LOGIN_STATUS_PACKET = 0x83,
	MESSAGE_PACKET = 0x85,
	SET_TIME_PACKET = 0x86,
	START_GAME_PACKET = 0x87,
	ADD_MOB_PACKET = 0x88,
	ADD_PLAYER_PACKET = 0x89,
	REMOVE_PLAYER_PACKET = 0x8a,
	ADD_ENTITY_PACKET = 0x8c,
	REMOVE_ENTITY_PACKET = 0x8d,
	ADD_ITEM_ENTITY_PACKET = 0x8e,
	TAKE_ITEM_ENTITY_PACKET = 0x8f,
	MOVE_ENTITY_PACKET = 0x90,
	ROTATE_HEAD_PACKET = 0x94,
	MOVE_PLAYER_PACKET = 0x95,
	//PLACE_BLOCK_PACKET = 0x96,
	REMOVE_BLOCK_PACKET = 0x97,
	UPDATE_BLOCK_PACKET = 0x98,
	ADD_PAINTING_PACKET = 0x99,
	EXPLODE_PACKET = 0x9a,
	LEVEL_EVENT_PACKET = 0x9b,
	TILE_EVENT_PACKET = 0x9c,
	ENTITY_EVENT_PACKET = 0x9d,
	PLAYER_EQUIPMENT_PACKET = 0xa0,
	PLAYER_ARMOR_EQUIPMENT_PACKET = 0xa1,
	INTERACT_PACKET = 0xa2,
	USE_ITEM_PACKET = 0xa3,
	PLAYER_ACTION_PACKET = 0xa4,
	HURT_ARMOR_PACKET = 0xa6,
	SET_ENTITY_DATA_PACKET = 0xa7,
	SET_ENTITY_MOTION_PACKET = 0xa8,
	//SET_ENTITY_LINK_PACKET = 0xa9,
	SET_HEALTH_PACKET = 0xaa,
	SET_SPAWN_POSITION_PACKET = 0xab,
	ANIMATE_PACKET = 0xac,
	RESPAWN_PACKET = 0xad,
	SEND_INVENTORY_PACKET = 0xae,
	DROP_ITEM_PACKET = 0xaf,
	CONTAINER_OPEN_PACKET = 0xb0,
	CONTAINER_CLOSE_PACKET = 0xb1,
	CONTAINER_SET_SLOT_PACKET = 0xb2,
	CONTAINER_SET_DATA_PACKET = 0xb3,
	CONTAINER_SET_CONTENT_PACKET = 0xb4,
	//CONTAINER_ACK_PACKET = 0xb5,
	CHAT_PACKET = 0xb6,
	ADVENTURE_SETTINGS_PACKET = 0xb7,
	ENTITY_DATA_PACKET = 0xb8,
	//PLAYER_INPUT_PACKET = 0xb9,
	FULL_CHUNK_DATA_PACKET = 0xba,
	UNLOAD_CHUNK_PACKET = 0xbb,
	SET_DIFFICULTY_PACKET = 0xbc,
};
#endif