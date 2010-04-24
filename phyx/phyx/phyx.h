/*
 *  phyx.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 4/17/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef phyx_H_
#define phyx_H_

#include <CoreFoundation/CoreFoundation.h>
#include <string>

#include "common/Globals.h"

class EntityManager;
class StateManager;
class TimerManager;
class Timer;
class EventManager;
class Entity;
class BaseEvent;
class Logger;
class BaseState;
class PhyxObject;
class BaseFunctor;

#define _RegisterForEvent(_type, _obj, _func, _event) Phyx->RegisterClient( (_event), new EventFunctor< _type >( (_obj), (_func) ) )
#define _UnregisterForEvent(_obj) Phyx->UnregisterClient( (_obj) )
#define _UnregisterForSingleEvent(_obj, _id) Phyx->UnregisterClient( (_obj), (_id) )

class phyx
{
public:
	/*	Public Data Members		*/
	
	// Entities
	EntityManager*	entities;
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	
	// Engine managers
	EntityManager*	m_pEntityManager;
	StateManager*	m_pStateManager;
	TimerManager*	m_pTimerManager;
	EventManager*	m_pEventManager;
	Logger*			m_pLogger;
	
	// For time keeping
	CFAbsoluteTime	m_currTime;
	CFAbsoluteTime	m_prevTime;
	float			m_fTimeSinceLaunch;
	
	// Instance of main engine object
	static phyx		sm_Instance;
	
public:
	/*	Public Functions		*/
	
	static phyx* GetInstance() { return &sm_Instance; }
	
	/**********************************
	 *	Function:	Init
	 *	Purpose:	initializes the manager should be called at launch of app.
	 **********************************/
	void Initialize();
	
	/**********************************
	 *	Function:	Shutdown
	 *	Purpose:	Shuts down the manager, should be called at end of app.
	 **********************************/
	void Shutdown();
	
	/**********************************
	 *	Function:	PreUpdate
	 *	Purpose:	anything that needs to execute pre main update
	 **********************************/
	void PreUpdate();
	
	/**********************************
	 *	Function:	Update
	 *	Purpose:	updates the manager
	 **********************************/
	void Update();
	
	/**********************************
	 *	Function:	PostUpdate
	 *	Purpose:	anything that must execture post main update
	 **********************************/
	void PostUpdate();
	
	/**********************************
	 *	Function:	PreRender
	 *	Purpose:	Anything that needs to execute pre main render
	 **********************************/
	void PreRender();
	
	/**********************************
	 *	Function:	Render
	 *	Purpose:	Call render on appropriate managers
	 **********************************/
	void Render();
	
	/**********************************
	 *	Function:	PostRender
	 *	Purpose:	Anything that needs to execute post main render
	 **********************************/
	void PostRender();
	
	/**********************************
	 *	Function:	GetDelta
	 *	Purpose:	Return the dt sense the last frame
	 *				Only valid between the PreUpdate and PostUpdate calls.
	 **********************************/
	float GetDelta() { return m_currTime - m_prevTime; }
	
	/*
	 *	Entity Manager forwards
	 */
	
	/**********************************
	 *	Function:	RegisterEntity
	 *	Purpose:	Register a new entity
	 **********************************/
	void RegisterEntity(PhyxObject* _entity);
	
	/*
	 *	Event Manager forwards
	 */
	
	/**********************************
	 *	Function:	RegisterClient
	 *	Purpose:	Forward a request for a new event to the event manager.
	 **********************************/
	void RegisterClient(unsigned _id, BaseFunctor* _functor);
	
	/**********************************
	 *	Function:	SendEvent
	 *	Purpose:	Forward a request for a new event to the event manager.
	 **********************************/
	void UnregisterClient(PhyxObject* _object);
	
	/**********************************
	 *	Function:	SendEvent
	 *	Purpose:	Forward a request for a new event to the event manager.
	 **********************************/
	void UnregisterClient(PhyxObject* _object, unsigned _id);
	
	/**********************************
	 *	Function:	SendEvent
	 *	Purpose:	Forward a request for a new event to the event manager.
	 **********************************/
	void SendEvent(unsigned _id, BaseEvent* _data = NULL, short _frameDelay = 0);
	
	/*
	 *	Timer Manager forwards
	 */
	
	/**********************************
	 *	Function:	RemoveTimer
	 *	Purpose:	Forward a request for a new event to the event manager.
	 **********************************/
	TimerHandle AddTimer( unsigned _event, BaseEvent* _data, float _firstTick, float _tickIncrement );
	
	/**********************************
	 *	Function:	RemoveTimer
	 *	Purpose:	Forward a request for a new event to the event manager.
	 **********************************/
	void RemoveTimer( Timer* _timer );
	
	/*
	 *	State manager forwards
	 */
	
	/**********************************
	 *	Function:	ChangeState
	 *	Purpose:	Pops off all current states and pushes on the new one
	 **********************************/
	void ChangeState(BaseState* _state);
	
	/**********************************
	 *	Function:	PushState
	 *	Purpose:	push a new state onto the state list
	 **********************************/
	void PushState(BaseState* _state);
	
	/**********************************
	 *	Function:	PopState
	 *	Purpose:	Pop the top state off the list
	 **********************************/
	void PopState();
	
	/**********************************
	 *	Function:	Clear
	 *	Purpose:	clear all the states
	 **********************************/
	void ClearStates();
	
	/*
	 *	Logger forwards
	 */
	
	/**********************************
	 *	Function:	LogMsg
	 *	Purpose:	Forward a request to log a message to the logger
	 **********************************/
	void LogMsg( std::string& _msg );
	
	/**********************************
	 *	Function:	Assert
	 *	Purpose:	Log a message if not _fail
	 **********************************/
	void Assert( bool _fail, std::string& _msg );
	
	/**********************************
	 *	Function:	ClearLogFile
	 *	Purpose:	Clear the log flie
	 **********************************/
	void ClearLogFile();
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	
	// Disabled functions.
	phyx();
	~phyx();
	phyx(const phyx&);
	phyx& operator=(const phyx&);
};

static phyx * const Phyx = phyx::GetInstance();

#endif