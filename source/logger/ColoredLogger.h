#pragma once

#ifdef _WIN32 
#include <windows.h>
#endif

#include <cstdlib>
#include <ctime>
#include <mutex>
#include <stdio.h>

class ColoredLogger
{
private:
	enum class LogLevel { Info, Debug, Notice, Warning, Error, Fatal };

	std::mutex logMutex;

private:
#ifdef WIN32
	HANDLE console;
#endif

public:
	ColoredLogger();

	void debug(const char* fmt, ...); // Debugging Stuff
	void info(const char* fmt, ...); // Information. Like initialization of a module
	void notice(const char* fmt, ...); // News. Like new player connecting
	void warning(const char* fmt, ...); // Warnings. Some thing that could cause an error later on
	void error(const char* fmt, ...); // Errors. Eg Unable to load a world
	void fatal(const char* fmt, ...); // Fatal error. Eg Unable to bind the socket

	void log(LogLevel level, const char* string);
};