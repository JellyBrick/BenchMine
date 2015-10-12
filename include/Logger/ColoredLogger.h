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

#ifndef COLOREDLOGGER_H_
#define COLOREDLOGGER_H_

#ifdef _WIN32 
#include <Windows.h>
#else
// UNIX Systems...
#endif

#include <ctime>
#include <mutex>
#include <stdio.h>

class ColoredLogger
{
private:
	enum class LogLevel { Info, Debug, Notice, Warning, Error, Fatal };

private:

#ifdef WIN32
	HANDLE _console;
#endif

	std::mutex* _lock;

public:
	ColoredLogger();
	~ColoredLogger();


	//NEVER Pass as argument std::string is going to end in acces violation
	void debug(const char* fmt, ...); // Debugging Stuff
	void info(const char* fmt, ...); // Information. Like initialization of a module
	void notice(const char* fmt, ...); // News. Like new player connecting
	void warning(const char* fmt, ...); // Warnings. Some thing that could cause an error later on
	void error(const char* fmt, ...); // Errors. Eg Unable to load a world
	void fatal(const char* fmt, ...); // Fatal error. Eg Unable to bind the socket

	void log(LogLevel level, const char* string);

};

#endif