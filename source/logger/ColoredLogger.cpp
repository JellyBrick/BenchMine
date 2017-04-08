#include "ColoredLogger.h"

ColoredLogger::ColoredLogger() {
#ifdef WIN32
	console = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
}

void ColoredLogger::debug(const char* fmt, ...) {
#ifdef NDEBUG
	return;
#endif

	va_list args;
	va_start(args, fmt);

	char buffer[4 * 1028];
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	log(LogLevel::Debug, buffer);
}

void ColoredLogger::info(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);

	char buffer[4 * 1028];
	vsnprintf(buffer, sizeof(buffer), fmt, args);

	va_end(args);

	log(LogLevel::Info, buffer);
}

void ColoredLogger::notice(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);

	char buffer[4 * 1028];
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	log(LogLevel::Notice, buffer);
}

void ColoredLogger::warning(const char* fmt, ...) {
	va_list args;

	va_start(args, fmt);
	char buffer[4 * 1028];
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	log(LogLevel::Warning, buffer);
}

void ColoredLogger::error(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);

	char buffer[4 * 1028];
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	log(LogLevel::Error, buffer);
}

void ColoredLogger::fatal(const char* fmt, ...) {
	va_list args;
	va_start(args, fmt);

	char buffer[4 * 1024];
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	log(LogLevel::Fatal, buffer);
	std::exit(EXIT_FAILURE);
}


void ColoredLogger::log(LogLevel level, const char* string) {
	std::lock_guard<std::mutex> lockGuard(logMutex);

	time_t now = time(nullptr);
	tm time = *localtime(&now); 

#ifdef WIN32
	switch (level) {
	case LogLevel::Info:
		SetConsoleTextAttribute(console, 0x0F); // INFO
		printf("[%02d:%02d:%02d][INFO]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Debug:
		SetConsoleTextAttribute(console, 0x07); // DEBUG
		printf("[%02d:%02d:%02d][DEBUG]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Notice:
		SetConsoleTextAttribute(console, 0x0B); // NOTICE
		printf("[%02d:%02d:%02d][NOTICE]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Warning:
		SetConsoleTextAttribute(console, 0x0E); // WARNING
		printf("[%02d:%02d:%02d][WARNING]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Error:
		SetConsoleTextAttribute(console, 0x0C); // ERROR
		printf("[%02d:%02d:%02d][ERROR]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Fatal:
		SetConsoleTextAttribute(console, 0x04); // FATAL
		printf("[%02d:%02d:%02d][FATAL]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	}

	//Reset Color
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
#else
	switch (level) {
	case LogLevel::Info:
		printf("[%02d:%02d:%02d][INFO]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Debug:
		printf("[%02d:%02d:%02d][DEBUG]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Notice:
		printf("[%02d:%02d:%02d][NOTICE]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Warning:
		printf("[%02d:%02d:%02d][WARNING]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Error:
		printf("[%02d:%02d:%02d][ERROR]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	case LogLevel::Fatal:
		printf("[%02d:%02d:%02d][FATAL]: %s\n", time.tm_hour, time.tm_min, time.tm_sec, string);
		break;
	}
#endif
}