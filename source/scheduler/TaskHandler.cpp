#include "TaskHandler.h"

#include <cassert>
#include <chrono>

unsigned int TaskHandler::ids = 1;

TaskHandler::TaskHandler() : TaskHandler(MAX_TICKS_PER_SECONDS) {}

TaskHandler::TaskHandler(unsigned int tickPerSeconds) {
	this->sleepIntervals = 1000 / tickPerSeconds;
	this->tick = 0;
	this->maxTicks = tickPerSeconds;
	this->isRunning = false;
}

TaskHandler::~TaskHandler() {
	this->removeAllTask();
}

unsigned int TaskHandler::addTask(Task* task) {
	assert(task != nullptr);

	if(task->delay != 0 && task->id == 0) {
		task->id = TaskHandler::ids++;
		this->tasks.push_back(task);
		return task->id;
	}

	return 0;
}

bool TaskHandler::removeTask(unsigned int id) {
	for (unsigned int i = 0; i < this->tasks.size(); i++) {
		Task* task = this->tasks[i];
		if (task->id == id) {
			this->tasks.erase(std::find(this->tasks.begin(), this->tasks.end(), task));
			delete task;
			return true;
		}
	}

	return false;
}

void TaskHandler::removeAllTask() {
	for (unsigned int i = 0; i < this->tasks.size(); i++) {
		delete this->tasks[i];
	}

	this->tasks.clear();
}

void TaskHandler::start() {
	
	this->isRunning = true;
	this->thread = std::thread(&TaskHandler::run, this);
}

void TaskHandler::stop() {
	if (this->isRunning) {
		this->isRunning = false;
		this->thread.join();
	}
}

void TaskHandler::run() {
	while (this->isRunning) {
		this->Tick();
		std::this_thread::sleep_for(std::chrono::milliseconds(this->sleepIntervals)); // This is a very bad way to do this. TODO: Do it the right way
	}
}

void TaskHandler::Tick() {
	for (size_t i = 0; i < this->tasks.size(); ++i) {
		Task *t = this->tasks[i];
		if (--t->delay == 0) {
			t->onRun();
			if (t->repeatTime == -1) {
				t->delay = t->defaultTick;
			} else if (t->repeatTime > 0) {
				if (--t->repeatTime == 0) {
					t->onComplete();
					this->tasks.erase(std::find(this->tasks.begin(), this->tasks.end(), t));
					delete t;
					continue;
				}

				t->delay = t->defaultTick;
			} else {
				t->onComplete();

				this->tasks.erase(std::find(this->tasks.begin(), this->tasks.end(), t));
				delete t;
			}
		}
	}
}