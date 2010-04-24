/*
 *  TimerManager.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "TimerManager.h"

TimerManager::TimerManager() :
	BaseManager()
{
}

TimerManager::~TimerManager()
{
}

TimerHandle TimerManager::AddTimer(unsigned _event, BaseEvent* _data, float _firstTick, float _tickIncrement)
{
	Timer* timer = new Timer( _event, _data, _firstTick, _tickIncrement );
	
	for ( int i = 0; i < m_vTimers.size(); ++i )
	{
		if ( !m_vTimers[i] )
		{
			m_vTimers[i] = timer;
			return i;
		}
	}
	
	m_vTimers.push_back( timer );
	return m_vTimers.size() - 1;
}

void TimerManager::RemoveTimer(Timer* _timer)
{
	for ( std::vector< Timer* >::iterator iter = m_vTimers.begin(); iter != m_vTimers.end(); ++iter )
	{
		if ( (*iter) == _timer )
		{
			delete (*iter);
			(*iter) = NULL;
			return;
		}
	}
}

void TimerManager::RemoveTimer(TimerHandle _handle)
{
	delete m_vTimers[_handle];
	m_vTimers[_handle] = NULL;
}

void TimerManager::Update(float _delta)
{
	for ( std::vector< Timer* >::iterator iter = m_vTimers.begin(); iter != m_vTimers.end(); ++iter )
	{
		if ( (*iter) )
		{
			(*iter)->Update( _delta );
		}
	}
}















