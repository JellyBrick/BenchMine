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
#ifndef TASK_H_
#define TASK_H_

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


#endif