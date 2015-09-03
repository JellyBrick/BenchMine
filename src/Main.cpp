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

int main(int argv, char** argc)
{
	std::cout << "Hello World" << std::endl;
	try
	{
		Server* server = Server::getInstance();
		server->Start();
	    while(true) {
	        if (std::cin.get() == 'q') {
	            delete server;
	            return 0;
	        }
	    }
	} catch(std::exception e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
