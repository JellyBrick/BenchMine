#include "TaskHandler.h"

#include <algorithm>
#include <cassert>
#include <chrono>

unsigned int TaskHandler::ids = 1;

TaskHandler::TaskHandler() : TaskHandler(MAX_TICKS_PER_SECONDS) {}

TaskHandler::TaskHandler(unsigned int tickPerSeconds) {
	sleepIntervals = 1000 / tickPerSeconds;
	tick = 0;
	maxTicks = tickPerSeconds;
	isRunning = false;
}

TaskHandler::~TaskHandler() {
	removeAllTask();
}

unsigned int TaskHandler::addTask(Task* task) {
	assert(task != nullptr);

	if(task->delay != 0 && task->id == 0) {
		task->id = TaskHandler::ids++;
		tasks.push_back(task);
		return task->id;
	}

	return 0;
}

bool TaskHandler::removeTask(unsigned int id) {
	for (unsigned int i = 0; i < tasks.size(); i++) {
		Task* task = tasks[i];
		if (task->id == id) {
			tasks.erase(std::find(tasks.begin(), tasks.end(), task));
			delete task;
			return true;
		}
	}

	return false;
}

void TaskHandler::removeAllTask() {
	for (unsigned int i = 0; i < tasks.size(); i++) {
		delete tasks[i];
	}

	tasks.clear();
}

void TaskHandler::start() {
	
	isRunning = true;
	thread = std::thread(&TaskHandler::run, this);
}

void TaskHandler::stop() {
	if (isRunning) {
		isRunning = false;
		thread.join();
	}
}

void TaskHandler::run() {
	while (isRunning) {
		Tick();
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepIntervals)); // This is a very bad way to do this. TODO: Do it the right way
	}
}

void TaskHandler::Tick() {
	for (size_t i = 0; i < tasks.size(); ++i) {
		Task *t = tasks[i];
		if (--t->delay == 0) {
			t->onRun();
			if (t->repeatTime == -1) {
				t->delay = t->defaultTick;
			} else if (t->repeatTime > 0) {
				if (--t->repeatTime == 0) {
					t->onComplete();
					tasks.erase(std::find(tasks.begin(), tasks.end(), t));
					delete t;
					continue;
				}

				t->delay = t->defaultTick;
			} else {
				t->onComplete();

				tasks.erase(std::find(tasks.begin(), tasks.end(), t));
				delete t;
			}
		}
	}
}
