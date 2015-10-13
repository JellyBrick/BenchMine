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

#ifndef TASKHANDLER_H_
#define TASKHANDLER_H_

#include <chrono>
#include <exception>
#include <thread>
#include <vector>

#include "Task.h"

class TaskHandler
{
public:
	static const int MAX_TICKS_PER_SECONDS = 20;

private:
	static unsigned int ids;

	unsigned int maxTicks;
	unsigned int sleepIntervals;
	unsigned int tick;

	bool isRunning;

	std::vector<Task*> _tasks;
	std::thread* _thread;

	void Tick();

public:
	TaskHandler(unsigned int tickPerSeconds);
	TaskHandler();

	void start();
	void stop();

	void run();

	unsigned int addTask(Task* t);
	bool removeTask(unsigned int id);
	void removeAllTask();

	~TaskHandler();

};

#endif // TaskHandler