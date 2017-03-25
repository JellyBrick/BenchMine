#pragma once

enum RaknetPacket : unsigned char {
	PING = 0x00,
	PONG = 0x03,

	CONNECTION_REQUEST = 0x09,
	CONNECTION_ACCEPTED = 0x10,

	WRAPPER = 0xFE
};
