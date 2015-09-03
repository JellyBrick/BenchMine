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

#include "Scheduler/Task.h"

Task::Task(int delay) : _delay(delay), _defaultTick(delay), _repeatTime(0) {}

Task::Task(int delay, int repeatsTime) : Task(delay)
{
	this->_repeatTime = repeatsTime;
}
