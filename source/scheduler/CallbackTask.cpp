#include "CallbackTask.h"

CallbackTask::CallbackTask(std::function<void()> callback, int delay) 
	: Task(delay), callback(callback) {}

CallbackTask::CallbackTask(std::function<void()> callback, int delay, int repeatTimes) 
	: Task(delay, repeatTimes), callback(callback) {}

void CallbackTask::onRun() {
	callback();
}

void CallbackTask::onComplete() {} // Not Used