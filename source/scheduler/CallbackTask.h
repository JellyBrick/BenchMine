#pragma once

#include <functional>

#include "Task.h"

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
