#include "CallbackTask.h"

CallbackTask::CallbackTask(std::function<void()> callback, int delay) : Task(delay) {
	this->_callback = callback;
}

CallbackTask::CallbackTask(std::function<void()> callback, int delay, int repeatTimes) : Task(delay, repeatTimes) {
	this->_callback = callback;
}

void CallbackTask::onRun() {
	this->_callback();
}

void CallbackTask::onComplete() {} // Not Used