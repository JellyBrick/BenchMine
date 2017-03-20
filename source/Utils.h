#pragma once

#include <string>
#include <vector>

class Utils {
public:
	static std::vector<std::string> explode(const std::string& string, const char delimiter);
};