#include "Task.h"

Task::Task(int delay) : id(0), delay(delay), defaultTick(delay), repeatTime(0) {}

Task::Task(int delay, unsigned int repeatsTime) : Task(delay) {
	this->repeatTime = repeatsTime;
}
