/*
 *  EventManager.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/21/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_

#include <utility>
#include <list>


#include "../common/Functors.h"
#include "../common/EventIds.h"
#include "../math/vec2.h"

class PhyxObject;

class BaseEvent
{
public:
	BaseEvent()			{ }
	virtual ~BaseEvent()	{ }
};



class Vec2Event : public BaseEvent
{
public:
	vec2	data;
	
	Vec2Event(const vec2& _v)					: data(_v)		{ }
	Vec2Event(const float _x, const float _y)	: data(_x, _y)	{ }
	~Vec2Event() {}
};



class EventManager
{
	friend class phyx;
public:
	/*	Public Data Members		*/
	struct pendingEvent
	{
		unsigned id;
		BaseEvent* data;
		short delay;
		pendingEvent(unsigned _id, BaseEvent* _data, short _delay) : id(_id), data(_data), delay(_delay) { }
	};
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	typedef	std::list< std::pair< unsigned, std::list< BaseFunctor* > > >	ClientDatabase;
	
	ClientDatabase									m_ClientDatabase;
	std::list< pendingEvent >						m_QueedEvents;
	std::list< std::pair< unsigned, BaseEvent* > >	m_CurrentEvents;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	RegisterClient
	 *	Purpose:	Register a functor with an event
	 **********************************/
	void RegisterClient(unsigned _id, BaseFunctor* _functor);
	
	/**********************************
	 *	Function:	UnregisterClient
	 *	Purpose:	Unregister a functor, functors must be
	 *				unregistered when an object is destroyed.
	 **********************************/
	void UnregisterClient(PhyxObject* _object);
	
	/**********************************
	 *	Function:	UnregisterClient
	 *	Purpose:	Unregister a functor, functors must be
	 *				unregistered when an object is destroyed.
	 **********************************/
	void UnregisterClient(PhyxObject* _functor, unsigned _id);
	
	/**********************************
	 *	Function:	SendEvent
	 *	Purpose:	Send an event which will be called on all registered functors
	 **********************************/
	void SendEvent(unsigned _id, BaseEvent* _data, short _frameDelay = 0);
	
	/**********************************
	 *	Function:	ProcessEvents
	 *	Purpose:	Prossess all current events
	 **********************************/
	void ProcessEvents(void);
	
	
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	EventManager();
	EventManager(const EventManager&);
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~EventManager();
};





#endif
