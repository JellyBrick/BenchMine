#pragma once

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

	std::vector<Task*> tasks;
	std::thread thread;

	void Tick();

public:
	TaskHandler();
	TaskHandler(unsigned int tickPerSeconds);

	void start();
	void stop();

	void run();

	unsigned int addTask(Task* t);
	bool removeTask(unsigned int id);
	void removeAllTask();

	~TaskHandler();
};