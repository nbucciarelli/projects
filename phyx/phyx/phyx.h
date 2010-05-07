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

#include "managers/AttributeManager.h"

class EntityManager;
class StateManager;
class Timer;
class EventManager;
class Entity;
class BaseEvent;
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
	EntityManager*		m_pEntityManager;
	StateManager*		m_pStateManager;
	EventManager*		m_pEventManager;
	AttributeManager*	m_pAttributeManager;
	
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
	void RegisterEntity(PhyxObject* _object);
	
	/**********************************
	 *	Function:	RemoveEntity
	 *	Purpose:	Register a new entity
	 **********************************/
	void RemoveEntity(PhyxObject* _object);
	
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
	 *	AttributeManager forwards
	 */
	
	/**********************************
	 *	Function:	SetAttr
	 *	Purpose:	Sets an attribute, creates it if nessessary.
	 **********************************/
	template <typename T>
	void SetAttr(PhyxObject* _obj, std::string& _attrName, T _attrValue)
	{ m_pAttributeManager->SetAttr<T>( _obj, _attrName, _attrValue ); }
	
	/**********************************
	 *	Function:	GetAttr
	 *	Purpose:	Gets an attribute, return NULL if it doesn't exist.
	 **********************************/
	template <typename T>
	const T * const GetAttr(PhyxObject* _obj, std::string& _attrName)
	{ return m_pAttributeManager->GetAttr<T>( _obj, _attrName ); }
	
	/**********************************
	 *	Function:	DetAttr
	 *	Purpose:	Delete an attribute.
	 **********************************/
	bool DelAttr(PhyxObject* _obj, std::string& _attrName);
	
	/**********************************
	 *	Function:	ClearObjAttrs
	 *	Purpose:	Clear all attributes from an obj.
	 **********************************/
	bool ClearObjAttrs(PhyxObject* _obj);
	
	
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