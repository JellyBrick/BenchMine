#pragma once

#include <packets/DataPacket.h>

#include "world/math/Vector3f.h"

class LevelSoundEvent : public RakLib::DataPacket {
public:
	enum Event {
		ITEM_USE_ON = 0,
		HIT = 1,
		STEP = 2,
		JUMP = 3,
		BREAK = 4,
		PLACE = 5,
		HEAVY_STEP = 6,
		GALLOP = 7,
		FALL = 8,
		AMBIENT = 9,
		AMBIENT_BABY = 10,
		AMBIENT_IN_WATER = 11,
		BREATHE = 12,
		DEATH = 13,
		DEATH_IN_WATER = 14,
		DEATH_TO_ZOMBIE = 15,
		HURT = 16,
		HURT_IN_WATER = 17,
		MAD = 18,
		BOOST = 19,
		BOW = 20,
		SQUISH_BIG = 21,
		SQUISH_SMALL = 22,
		FALL_BIG = 23,
		FALL_SMALL = 24,
		SPLASH = 25,
		FIZZ = 26,
		FLAP = 27,
		SWIM = 28,
		DRINK = 29,
		EAT = 30,
		TAKEOFF = 31,
		SHAKE = 32,
		PLOP = 33,
		LAND = 34,
		SADDLE = 35,
		ARMOR = 36,
		ADD_CHEST = 37,
		THROW = 38,
		ATTACK = 39,
		ATTACK_NODAMAGE = 40,
		WARN = 41,
		SHEAR = 42,
		MILK = 43,
		THUNDER = 44,
		EXPLODE = 45,
		FIRE = 46,
		IGNITE = 47,
		FUSE = 48,
		STARE = 49,
		SPAWN = 50,
		SHOOT = 51,
		BREAK_BLOCK = 52,
		REMEDY = 53,
		UNFECT = 54,
		LEVELUP = 55,
		BOW_HIT = 56,
		BULLET_HIT = 57,
		EXTINGUISH_FIRE = 58,
		ITEM_FIZZ = 59,
		CHEST_OPEN = 60,
		CHEST_CLOSED = 61,
		POWER_ON = 62,
		POWER_OFF = 63,
		ATTACH = 64,
		DETACH = 65,
		DENY = 66,
		TRIPOD = 67,
		POP = 68,
		DROP_SLOT = 69,
		NOTE = 70,
		THORNS = 71,
		PISTON_IN = 72,
		PISTON_OUT = 73,
		PORTAL = 74,
		WATER = 75,
		LAVA_POP = 76,
		LAVA = 77,
		BURP = 78,
		BUCKET_FILL_WATER = 79,
		BUCKET_FILL_LAVA = 80,
		BUCKET_EMPTY_WATER = 81,
		BUCKET_EMPTY_LAVA = 82,
		GUARDIAN_FLOP = 83,
		MOB_ELDERGUARDIAN_CURSE = 84,
		MOB_WARNING = 85,
		MOB_WARNING_BABY = 86,
		TELEPORT = 87,
		SHULKER_OPEN = 88,
		SHULKER_CLOSE = 89,
		HAGGLE = 90,
		HAGGLE_YES = 91,
		HAGGLE_NO = 92,
		HAGGLE_IDLE = 93,
		DEFAULT = 94,
		UNDEFINED = 95,
	};

	Event eventID;
	Vector3f eventPosition;
	uint32 extraData;
	uint32 pitch;
	bool unknown1;
	bool unknown2;

public:
	LevelSoundEvent();

	void decode() override;

	void encode() override;
};