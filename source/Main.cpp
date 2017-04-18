#include <iostream>

#include "Server.h"

int main(int argv, char** argc) {
	Server server;
	server.start();
	std::cin.get();
	return 0;
}