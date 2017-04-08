#pragma once

class TaskHandler;
class Task
{
private:
	friend TaskHandler;
	
	unsigned int id;
	int delay;
	int defaultTick;

	unsigned int repeatTime;

public:
	Task(int delay);
	Task(int delay, unsigned int repeatsTime);

	virtual void onRun() = 0;
	virtual void onComplete() = 0;

	inline unsigned int getID() const { return id; }
	inline int getDelay() const { return  delay; }
	inline unsigned int getReapeatTme() const { return repeatTime; };
};