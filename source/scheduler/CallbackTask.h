#pragma once

#include <functional>

#include "Task.h"

class CallbackTask final : public Task
{
private:
	std::function<void()> callback;

public:
	CallbackTask(std::function<void()> callback, int delay);
	CallbackTask(std::function<void()> callback, int delay, int repeatTimes);

	void onRun() override;
	void onComplete() override;
};
