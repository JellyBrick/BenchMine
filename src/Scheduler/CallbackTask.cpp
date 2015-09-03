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


#include "Scheduler/CallbackTask.h"

CallbackTask::CallbackTask(std::function<void()> callback, int delay) : Task(delay)
{
	this->_callback = callback;
}

CallbackTask::CallbackTask(std::function<void()> callback, int delay, int repeatTimes) : Task(delay, repeatTimes)
{
	this->_callback = callback;
}

void CallbackTask::onRun()
{
	this->_callback();
}

void CallbackTask::onComplete()
{
	//TODO
}