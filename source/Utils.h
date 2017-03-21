#pragma once

#include <string>
#include <vector>

class Utils {
public:

	// String Utils
	static std::vector<std::string> explode(const std::string& string, const char delimiter);

	// Console Utils
	static void setConsoleTitle(const std::string& title);
};