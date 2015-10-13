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

#include <iostream>

#include "Server.h"

int main(int argv, char** argc) {
	//Should I pass the logger from here?
	Server server;
	server.start();
	std::cin.get();
	return 0;
}
