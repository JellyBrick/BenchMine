#pragma once

#include <string>

#include <RakLib/protocol/DataPacket.h>

class Disconnect : public RakLib::DataPacket {
public:
	bool messageHided;
	std::string message;

public:
	Disconnect(const std::string& message);

	void encode() override;
};