#include "Login.h"

#include "common/Compression.h"
#include "common/Utils.h"

Login::Login(std::unique_ptr<Packet>&& packet) : DataPacket(std::move(packet)) {
	this->protocol = 0;
	this->edition = 0x00;
}

void Login::decode() {
	static const uint32 JSON_DECOMPRESSION_SIZE = 1024 * 1024 * 8;
	this->position = 2; // Skip Wrapper and Packet ID

	this->protocol = this->getInt();
	this->edition = this->getByte();

	this->position += sizeof(int16); // Skip payload length
	uint8* payload = this->buffer + this->position;
	uint32 payloadSize = this->length - this->position;

	uint8* output = new uint8[JSON_DECOMPRESSION_SIZE];
	uint32 outputSize = Compression::decompress(payload, payloadSize, output, JSON_DECOMPRESSION_SIZE);

	if (outputSize == 0) {
		delete[] output;
		return;
	}

	auto chain = this->getRealChain((char*)(output + sizeof(int32))); // We have to skip the string length (int)
	delete[] output;

	if (chain.has<jsonxx::Object>("extraData")) {
		jsonxx::Object extraData = chain.get<jsonxx::Object>("extraData");
		if (extraData.has<jsonxx::String>("displayName")) {
			this->displayName = extraData.get<jsonxx::String>("displayName");
		}

		if (extraData.has<jsonxx::String>("identity")) {
			this->clientUUID = extraData.get<jsonxx::String>("identity");
		}
	}

	if (chain.has<jsonxx::String>("identityPublicKey")) {
		this->identityPublicKey = chain.get<jsonxx::String>("identityPublicKey");
	}
}

jsonxx::Object Login::getRealChain(const std::string& json) const {
	static const int EXTRA_DATA_INDEX = 1;

	jsonxx::Object object;
	object.parse(json);
	if (object.has<jsonxx::Array>("chain")) {
		jsonxx::String chain = object.get<jsonxx::Array>("chain").get<jsonxx::String>(0);
		auto tokens = Utils::explode(chain, '.');
		object.parse(Utils::base64_decode(tokens[EXTRA_DATA_INDEX]));
	}

	return std::move(object);
}
