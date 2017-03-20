#include "TaskHandler.h"

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

unsigned int TaskHandler::addTask(Task* t) {
	if (t == nullptr) {
		return 0;
	}

	if(t->_delay != 0 && t->_id == 0) {
		t->_id = TaskHandler::ids++;
		this->_tasks.push_back(t);
		return t->_id;
	}

	return 0;
}

bool TaskHandler::removeTask(unsigned int id) {
	for (unsigned int i = 0; i < this->_tasks.size(); i++) {
		Task* task = this->_tasks[i];
		if (task->_id == id) {
			this->_tasks.erase(std::find(this->_tasks.begin(), this->_tasks.end(), task));
			delete task;
			return true;
		}
	}

	return false;
}

void TaskHandler::removeAllTask() {
	for (unsigned int i = 0; i < this->_tasks.size(); i++) {
		delete this->_tasks[i];
	}

	this->_tasks.clear();
}

void TaskHandler::start() {
	this->isRunning = true;
	this->_thread = std::thread(&TaskHandler::run, this);
}

void TaskHandler::stop() {
	if (this->isRunning) {
		this->isRunning = false;
		this->_thread.join();
	}
}

void TaskHandler::run() {
	while (this->isRunning) {
		this->Tick();
		std::this_thread::sleep_for(std::chrono::milliseconds(this->sleepIntervals)); // This is a very bad way to do this. TODO: Do it the right way
	}
}

void TaskHandler::Tick() {
	if (!this->_tasks.empty()) {
		for (unsigned int i = 0; i < this->_tasks.size(); ++i) {
			Task *t = this->_tasks[i];
			if (--t->_delay == 0) {
				t->onRun();
				if (t->_repeatTime == -1) {
					t->_delay = t->_defaultTick;
				} else if (t->_repeatTime > 0) {
					if (--t->_repeatTime == 0) {
						t->onComplete();
						this->_tasks.erase(std::find(this->_tasks.begin(), this->_tasks.end(), t));
						delete t;
						continue;
					}

					t->_delay = t->_defaultTick;
				} else {
					t->onComplete();

					this->_tasks.erase(std::find(this->_tasks.begin(), this->_tasks.end(), t));
					delete t;
				}
			}
		}
	}
}