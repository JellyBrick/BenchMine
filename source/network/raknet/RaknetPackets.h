#pragma once

enum RaknetPacket : unsigned char {
	PING = 0x00,
	PONG = 0x03,

	CONNECTION_REQUEST = 0x09,
	CONNECTION_ACCEPTED = 0x10,

	SERVER_FULL = 0x14,
	DISCONNECT = 0x15,

	BANNED = 0x17,

	WRAPPER = 0xFE
};
