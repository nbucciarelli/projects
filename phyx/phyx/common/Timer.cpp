/*
 *  Timer.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "../phyx.h"
#include "../managers/EventManager.h"
#include "../managers/TimerManager.h"
#include "Timer.h"

Timer::Timer(unsigned _event, BaseEvent* _data, float _firstTick, float _tickIncrement):
	m_eEvent( _event ),
	m_pData( _data ),
	m_fCurrTime( _firstTick ),
	m_fIncrementTime( _tickIncrement )
{
}

Timer::~Timer()
{
	if ( m_pData )
	{
		delete m_pData;
	}
}

void Timer::Update(float _delta)
{
	m_fCurrTime -= _delta;
	if ( m_fCurrTime < 0.0f )
	{
		Phyx->SendEvent( m_eEvent, m_pData, 0 );
		m_fCurrTime = m_fIncrementTime;
		if ( m_fIncrementTime == 0 )
			Phyx->RemoveTimer( this );
	}
}





