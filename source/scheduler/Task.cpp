#include "Task.h"

Task::Task(int delay) : _delay(delay), _defaultTick(delay), _repeatTime(0) {}

Task::Task(int delay, unsigned int repeatsTime) : Task(delay) {
	this->_repeatTime = repeatsTime;
}
