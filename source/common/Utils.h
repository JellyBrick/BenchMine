#pragma once

#include <string>
#include <vector>

class Utils {
public:

	// String Utils
	static std::vector<std::string> explode(const std::string& string, const char delimiter);

	/*
	 * SOURCE: http://renenyffenegger.ch/notes/development/Base64/Encoding-and-decoding-base-64-with-cpp
	 * AUTHOR: René Nyffenegger
	 */
	static std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len);

	/*
	 * SOURCE: http://renenyffenegger.ch/notes/development/Base64/Encoding-and-decoding-base-64-with-cpp
	 * AUTHOR: René Nyffenegger
	 */
	static std::string base64_decode(std::string const& encoded_string);

	// Console Utils
	static void setConsoleTitle(const std::string& title);
};