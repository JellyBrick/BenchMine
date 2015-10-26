/**
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* @author InusualZ
*
*
*/

#include "Utils.h"

std::vector<std::string> Utils::explode(const std::string& string, const char delimiter) {
	std::vector<std::string> result;
	unsigned int start = 0, pos = 0;

	while (pos != string.length()) {
		if (string.at(pos) == delimiter || pos + 1 == string.length()) {
			unsigned int size = (pos - start) + ((pos + 1) == string.length() ? 1 : 0);
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