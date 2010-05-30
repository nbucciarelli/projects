/*
 *  EventManager.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/21/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "EventManager.h"

#include "../objects/PhyxObject.h"
#include "../common/Logger.h"


EventManager::EventManager()
{
}

EventManager::~EventManager()
{
}

void EventManager::RegisterClient(unsigned _id, BaseFunctor* _functor, EVENT_PRIORITY _priority)
{
	// Go through the list of event lists
	InsertPrioritizedListener( m_ClientDatabase[ _id ], _functor, _priority );
}

void EventManager::InsertPrioritizedListener(PrioritizedListenerList& _prioritizedListenerList, BaseFunctor* _functor, EVENT_PRIORITY _priority)
{
	while ( _prioritizedListenerList.size() <= _priority )
	{
		_prioritizedListenerList.push_back( ListenerList() );
	}
	_prioritizedListenerList[ (unsigned)_priority ].push_back( _functor );
}

void EventManager::RemovePrioritizedListener(PrioritizedListenerList& _prioritizedListenerList, PhyxObject* _object)
{
	for (PrioritizedListenerList::iterator plliter = _prioritizedListenerList.begin(); plliter != _prioritizedListenerList.end(); ++plliter)
	{
		for (ListenerList::iterator lliter = (*plliter).begin(); lliter != (*plliter).end(); ++plliter)
		{
			if ((*lliter)->GetOwner() == _object)
			{
				delete (*lliter);
				(*plliter).erase(lliter);
				return;
			}
		}
	}
}

void EventManager::UnregisterClient(PhyxObject* _object)
{
	for (ClientDatabase::iterator cditer = m_ClientDatabase.begin(); cditer != m_ClientDatabase.end(); ++cditer)
	{
		RemovePrioritizedListener( (*cditer).second, _object );
	}
}

void EventManager::UnregisterClient(PhyxObject* _object, unsigned _id)
{
	RemovePrioritizedListener( m_ClientDatabase[ _id ], _object );
}

void EventManager::SendEvent(unsigned _id, BaseEvent* _data, short _frameDelay)
{
	if ( _frameDelay == -1 )
	{
		EventDataPair eventData( _id, _data );
		DispatchEvent( eventData );
	}
	else
	{
		m_QueedEvents.push_back( EventManager::pendingEvent( _id, _data, _frameDelay ) );
	}
}

void EventManager::ProcessEvents(void)
{
	for (std::list< pendingEvent >::iterator iter = m_QueedEvents.begin(); iter != m_QueedEvents.end(); ++iter)
	{
		if ((*iter).delay == 0)
		{
			m_CurrentEvents.push_back( EventDataPair( (*iter).id, (*iter).data ) );
			iter = m_QueedEvents.erase(iter);
			continue;
		}
		
		(*iter).delay--;
	}
	
	while (!m_CurrentEvents.empty())
	{
		DispatchEvent( m_CurrentEvents.front() );
		m_CurrentEvents.pop_front();
	}
}

void EventManager::DispatchEvent( EventDataPair& _event )
{
	for (PrioritizedListenerList::iterator plliter = m_ClientDatabase[ _event.first ].begin(); plliter != m_ClientDatabase[ _event.first ].end(); ++plliter)
	{
		for (ListenerList::iterator lliter = (*plliter).begin(); lliter != (*plliter).end(); ++lliter)
		{
			if (!(*(*lliter))(_event.second))
			{
				if ( _event.second != NULL )
				{
					delete _event.second;
				}
				return;
			}
		}
	}
	
}








