#pragma once

class TaskHandler;
class Task
{
private:
	friend TaskHandler;
	
	unsigned int _id;
	int _delay;
	int _defaultTick;

	unsigned int _repeatTime;

public:

	Task(int delay);
	Task(int delay, unsigned int repeatsTime);

	virtual void onRun() = 0;
	virtual void onComplete() = 0;

	inline unsigned int getID() const { return this->_id; }
	inline int getDelay() const { return this-> _delay; }
	inline unsigned int getReapeatTme() const { return this->_repeatTime; };
};