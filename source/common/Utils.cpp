#include "Utils.h"

#ifdef _WIN32
#include <Windows.h>
#endif

std::vector<std::string> Utils::explode(const std::string& string, const char delimiter) {
	std::vector<std::string> result;
	unsigned int start = 0, pos = 0;

	while (pos != string.length()) {
		if (string.at(pos) == delimiter || pos + 1 == string.length()) {
			unsigned size = pos - start + (pos + 1 == string.length() ? 1 : 0);
			if (size != 0) { // Make this 'if' as a option? like a parameter with removeEmptyString?
				result.push_back(string.substr(start, size));
			}
			start = pos + 1;
		}
		pos++;
	}

	result.shrink_to_fit();
	return result;
}

static bool is_base64(unsigned char c) {
	return isalnum(c) || c == '+' || c == '/';
}

std::string Utils::base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
	static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	std::string ret;
	int i = 0, j = 0;
	unsigned char char_array_3[3], char_array_4[4];
	while (in_len--) {
		char_array_3[i++] = *(bytes_to_encode++);
		if (i == 3) {
			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for (i = 0; i < 4; ++i) {
				ret += base64_chars[char_array_4[i]];
			}

			i = 0;
		}
	}

	if (i) {
		for (j = i; j < 3; ++j) {
			char_array_3[j] = '\0';
		}

		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;

		for (j = 0; j < i + 1; j++)
			ret += base64_chars[char_array_4[j]];

		while (i++ < 3)
			ret += '=';

	}

	return ret;

}

std::string Utils::base64_decode(std::string const& encoded_string) {
	static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	int inLenght = encoded_string.size();
	int i = 0, j = 0, index = 0;
	unsigned char char_array_4[4], char_array_3[3];
	std::string ret;
	while (inLenght-- && encoded_string[index] != '=' && is_base64(encoded_string[index])) {
		char_array_4[i++] = encoded_string[index++]; 
		
		if (i == 4) {
			for (i = 0; i < 4; ++i) {
				char_array_4[i] = base64_chars.find(char_array_4[i]);
			}

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (i = 0; i < 3; ++i) {
				ret += char_array_3[i];
			}

			i = 0;
		}
	}

	if (i) {
		for (j = i; j < 4; ++j) {
			char_array_4[j] = 0;
		}

		for (j = 0; j < 4; ++j) {
			char_array_4[j] = base64_chars.find(char_array_4[j]);
		}

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for (j = 0; j < i - 1; ++j) {
			ret += char_array_3[j];
		}
	}

	return ret;
}

void Utils::setConsoleTitle(const std::string& title) {
#ifdef _WIN32
	SetConsoleTitle(title.c_str());
#else // Unix
	//TODO
#endif 
}