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

#ifndef CALLBACKTASK_H_
#define CALLBACKTASK_H_

#include "Task.h"

#include <functional>

class CallbackTask : public Task
{
private:
	std::function<void()> _callback;

public:
	CallbackTask(std::function<void()> callback, int delay);
	CallbackTask(std::function<void()> callback, int delay, int repeatTimes);

	void onRun() override;
	void onComplete() override;
};

#endif