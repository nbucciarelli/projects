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


EventManager::EventManager()
{
}

EventManager::~EventManager()
{
}

void EventManager::RegisterClient(unsigned _id, BaseFunctor* _functor)
{
	// Go through the list of event lists
	for (ClientDatabase::iterator iter = m_ClientDatabase.begin(); iter != m_ClientDatabase.end(); ++iter)
	{
		// if this is the event we're adding the functor too then add it to the list
		if ((*iter).first == _id)
		{
			(*iter).second.push_back( _functor );
			return;
		}
	}
	
	// If we didn't find a list we need to add a new one.
	m_ClientDatabase.push_back( std::pair< unsigned, std::list< BaseFunctor* > >( _id, std::list< BaseFunctor* >() ) );
	m_ClientDatabase.back().second.push_back( _functor );
}

void EventManager::UnregisterClient(PhyxObject* _object)
{
	for (ClientDatabase::iterator iter = m_ClientDatabase.begin(); iter != m_ClientDatabase.end(); ++iter)
	{
		for (std::list< BaseFunctor* >::iterator iter2 = (*iter).second.begin(); iter2 != (*iter).second.end(); ++iter2)
		{
			if ((*iter2)->GetOwner() == _object)
			{
				delete (*iter2);
				(*iter).second.erase(iter2);
				break;
			}
		}
	}
}

void EventManager::UnregisterClient(PhyxObject* _object, unsigned _id)
{
	for (ClientDatabase::iterator iter = m_ClientDatabase.begin(); iter != m_ClientDatabase.end(); ++iter)
	{
		if ((*iter).first == _id)
		{
			for (std::list< BaseFunctor* >::iterator iter2 = (*iter).second.begin(); iter2 != (*iter).second.end(); ++iter2)
			{
				if ((*iter2)->GetOwner() == _object)
				{
					delete (*iter2);
					(*iter).second.erase(iter2);
					return;
				}
			}
		}
	}
}

void EventManager::SendEvent(unsigned _id, BaseEvent* _data, short _frameDelay)
{
	m_QueedEvents.push_back( EventManager::pendingEvent( _id, _data, _frameDelay ) );
}

void EventManager::ProcessEvents(void)
{
	for (std::list< pendingEvent >::iterator iter = m_QueedEvents.begin(); iter != m_QueedEvents.end(); ++iter)
	{
		if ((*iter).delay == 0)
		{
			m_CurrentEvents.push_back( std::pair< unsigned, BaseEvent* >( (*iter).id, (*iter).data ) );
			iter = m_QueedEvents.erase(iter);
			continue;
		}
		
		(*iter).delay--;
	}
	
	while (!m_CurrentEvents.empty())
	{
		for (ClientDatabase::iterator iter = m_ClientDatabase.begin(); iter != m_ClientDatabase.end(); ++iter)
		{
			if (m_CurrentEvents.front().first == (*iter).first)
			{
				for (std::list< BaseFunctor* >::iterator iter2 = (*iter).second.begin(); iter2 != (*iter).second.end(); ++iter2)
				{
					if (!(*(*iter2))(m_CurrentEvents.front().first, m_CurrentEvents.front().second))
					{
						break;
					}
				}
				
				// We've dispatched this event to all clients
				break;
			}
		}
		
		// remove front event now that we're done with it
		delete m_CurrentEvents.front().second;
		m_CurrentEvents.pop_front();
	}
}









