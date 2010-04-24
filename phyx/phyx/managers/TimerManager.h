/*
 *  TimerManager.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef TimerManager_H_
#define TimerManager_H_

#include <vector>

#include "../common/Timer.h"
#include "../common/Globals.h"

#include "BaseManager.h"
class TimerManager : public BaseManager
{
	friend class phyx;
	friend class Timer;
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	std::vector< Timer* > m_vTimers;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	RegisterTimer
	 *	Purpose:	Add a new timer
	 **********************************/
	TimerHandle AddTimer(unsigned _event, BaseEvent* _data, float _firstTick, float _tickIncrement);
	
	/**********************************
	 *	Function:	RemoveTimer
	 *	Purpose:	Deletes a timer.
	 **********************************/
	void RemoveTimer(TimerHandle _handle);
	
	/**********************************
	 *	Function:	Update
	 *	Purpose:	update all timers
	 **********************************/
	void Update(float _delta);
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	TimerManager();
	TimerManager(const TimerManager&);
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~TimerManager();
	
	/**********************************
	 *	Function:	RegisterTimer
	 *	Purpose:	Add a new timer
	 **********************************/
	void RemoveTimer(Timer* _timer);
};

#endif