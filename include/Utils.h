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

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <string>
#include <vector>

class Utils {
public:
	static std::vector<std::string> explode(const std::string& string, const char delimiter);

};

#endif //UTILITIES_H_