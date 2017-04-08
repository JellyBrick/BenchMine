#include "Login.h"

#include "common/Compression.h"
#include "common/Utils.h"

Login::Login(std::unique_ptr<Packet>&& packet) : DataPacket(std::move(packet)) {
	protocol = 0;
	edition = 0x00;
}

void Login::decode() {
	static const uint32 JSON_DECOMPRESSION_SIZE = 1024 * 1024 * 8;
	++position; // Skip Packet ID

	protocol = getInt();
	edition = getByte();

	uint32 payloadSize = getVarUInt();
	uint8* payload = buffer + position;
	
	uint8* output = new uint8[JSON_DECOMPRESSION_SIZE];
	uint32 outputSize = Compression::decompress(payload, payloadSize, output, JSON_DECOMPRESSION_SIZE);

	if (outputSize == 0) {
		delete[] output;
		return;
	}

	auto chain = getRealChain(reinterpret_cast<char*>(output + sizeof(int32))); // We have to skip the string length (int)
	delete[] output;

	if (chain.has<jsonxx::Object>("extraData")) {
		jsonxx::Object extraData = chain.get<jsonxx::Object>("extraData");
		if (extraData.has<jsonxx::String>("displayName")) {
			displayName = extraData.get<jsonxx::String>("displayName");
		}

		if (extraData.has<jsonxx::String>("identity")) {
			clientUUID = extraData.get<jsonxx::String>("identity");
		}
	}

	if (chain.has<jsonxx::String>("identityPublicKey")) {
		identityPublicKey = chain.get<jsonxx::String>("identityPublicKey");
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
