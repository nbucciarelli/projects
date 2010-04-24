/*
 *  Timer.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef Timer_H_
#define Timer_H_

#include "EventIds.h"

class BaseEvent;

class Timer
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	float		m_fCurrTime;
	float		m_fIncrementTime;
	unsigned	m_eEvent;
	BaseEvent*	m_pData;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	Timer(unsigned _event, BaseEvent* _data, float _firstTick, float _tickIncrement);
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~Timer();
	
	/**********************************
	 *	Function:	Update
	 *	Purpose:	update the timer
	 **********************************/
	void Update(float _delta);
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif