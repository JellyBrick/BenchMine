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

#include "Logger/ColoredLogger.h"


ColoredLogger::ColoredLogger()
{
	this->_lock = new std::mutex(); // Should I use `std::unique_lock`?

#ifdef WIN32
	this->_console = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
}


ColoredLogger::~ColoredLogger()
{
	delete this->_lock;
}

void ColoredLogger::debug(const char* fmt, ...)
{
	//Better option: Log verbose level?
#ifdef NDEBUG
	return;
#else
	this->_lock->lock();

	va_list args;
	va_start(args, fmt);

	char* buffer = new char[4 * 1028];
	vsnprintf(buffer, 4 * 1028, fmt, args);
	
	va_end(args);


	this->log(LogLevel::Debug, buffer);
	delete buffer;

	this->_lock->unlock();
#endif
}

void ColoredLogger::info(const char* fmt, ...)
{
	//this->_lock->lock();

	va_list args;
	va_start(args, fmt);

	char* buffer = new char[4 * 1028];
	vsnprintf(buffer, 4 * 1028, fmt, args);

	va_end(args);

	this->log(LogLevel::Info, buffer);
	delete buffer;

	//this->_lock->unlock();
}

void ColoredLogger::notice(const char* fmt, ...)
{
	this->_lock->lock();

	va_list args;
	va_start(args, fmt);

	char* buffer = new char[4 * 1028];
	vsnprintf(buffer, 4 * 1028, fmt, args);

	va_end(args);


	this->log(LogLevel::Notice, buffer);
	delete buffer;

	this->_lock->unlock();
}

void ColoredLogger::warning(const char* fmt, ...)
{
	this->_lock->lock();

	va_list args;
	va_start(args, fmt);

	char* buffer = new char[4 * 1028];
	vsnprintf(buffer, 4 * 1028, fmt, args);

	va_end(args);


	this->log(LogLevel::Warning, buffer);
	delete buffer;

	this->_lock->unlock();
}

void ColoredLogger::error(const char* fmt, ...)
{
	this->_lock->lock();

	va_list args;
	va_start(args, fmt);

	char* buffer = new char[4 * 1028];
	vsnprintf(buffer, 4 * 1028, fmt, args);
	va_end(args);


	this->log(LogLevel::Error, buffer);
	delete buffer;

	this->_lock->unlock();
}

void ColoredLogger::fatal(const char* fmt, ...)
{
	this->_lock->lock();

	va_list args;
	va_start(args, fmt);

	char* buffer = new char[4 * 1024];
	vsnprintf(buffer, 4 * 1028, fmt, args);

	va_end(args);


	this->log(LogLevel::Fatal, buffer);
	delete buffer;

	this->_lock->unlock();

	std::exit(EXIT_FAILURE);
}


void ColoredLogger::log(LogLevel level, const char* string)
{
	//Should I move the locking/unlocking of the mutex to here?
	time_t now = time(nullptr);
	tm time = *localtime(&now); // I have to dereference this because then I can't delete it later on.... Why? This get deleted?

#ifdef WIN32
	switch (level)
	{
	case LogLevel::Info:
		SetConsoleTextAttribute(this->_console, 0x0F); // INFO
		printf("[%02d:%02d:%02d][INFO]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Debug:
		SetConsoleTextAttribute(this->_console, 0x07); // DEBUG
		printf("[%02d:%02d:%02d][DEBUG]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Notice:
		SetConsoleTextAttribute(this->_console, 0x0B); // NOTICE
		printf("[%02d:%02d:%02d][NOTICE]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Warning:
		SetConsoleTextAttribute(this->_console, 0x0E); // WARNING
		printf("[%02d:%02d:%02d][WARNING]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Error:
		SetConsoleTextAttribute(this->_console, 0x0C); // ERROR
		printf("[%02d:%02d:%02d][ERROR]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Fatal:
		SetConsoleTextAttribute(this->_console, 0x04); // FATAL
		printf("[%02d:%02d:%02d][FATAL]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	}

	//Reset Color
	SetConsoleTextAttribute(this->_console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#else
	//TODO
#endif
}