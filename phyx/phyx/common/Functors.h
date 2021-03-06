/*
 *  Functors.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef Functors_H_
#define Functors_H_

//
//
//  Additional functors will be added as needed.
//	Names should follow the pattern (returnType Abv)TemplatedFunctor(list of parameter Abv's)
//
//

#include "EventIds.h"

class BaseEvent;
class PhyxObject;

class BaseFunctor
{
public:
	BaseFunctor() {}
	~BaseFunctor() {}
	
	/**********************************
	 *	Function:	Operator()
	 *	Purpose:	Call the function pointed to by the functor.
	 **********************************/
	virtual bool operator()(BaseEvent* _data = 0 /* NULL */) { return true; }
	
	virtual bool operator==(const BaseFunctor& _other) { return true; }
	
	virtual const PhyxObject * const GetOwner() const { return 0; }
};


template <typename T>
class EventFunctor : public BaseFunctor
{
private:
	/*	Private Data Members	*/
	T*		m_pOwner;
	bool	(T::*m_pEventHandler)(BaseEvent*);
	
public:
	/*	Public Functions		*/
	EventFunctor(T* _owner, bool (T::*_pEventHandler)(BaseEvent*)) 
	{ 
		m_pOwner = _owner; 
		m_pEventHandler = _pEventHandler; 
	}
	
	~EventFunctor() {}
	
	bool operator()(BaseEvent* _data = 0 /* NULL */)
	{
		return (m_pOwner->*m_pEventHandler)(_data);
	}
	bool operator==(const EventFunctor& _func)
	{ return (m_pOwner == _func.m_pOwner && m_pEventHandler == _func.m_pEventHandler); }
	
	const PhyxObject * const GetOwner() const	{ return m_pOwner; }
};


#endif