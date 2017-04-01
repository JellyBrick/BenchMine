#include <iostream>

#include "Server.h"

int main(int argv, char** argc) {
	//Should I pass the logger from here?
	Server server;
	server.start();
	std::cin.get();
	return 0;
}