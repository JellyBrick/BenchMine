#pragma once

#include <vector>

#include <packets/DataPacket.h>

class Text : public RakLib::DataPacket {
public:
	enum Type {
		RAW = 0,
		CHAT = 1,
		TRANSLATION = 2,
		POPUP = 3,
		TIP = 4,
		SYSTEM = 5,
		WHISPER = 6,
	};

	Type type;
	std::string source;
	std::string message;
	std::vector<std::string> parameters;

public:
	Text();

	void decode() override;

	void encode() override;
};
