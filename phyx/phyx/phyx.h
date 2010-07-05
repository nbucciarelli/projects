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
#include "common/Globals.h"

class EntityManager;
class StateManager;
class Timer;
class EventManager;
class Entity;
class BaseEvent;
class BaseState;
class PhyxObject;
class BaseFunctor;
class Camera;

#define _NewEventFunctor(_type, _obj, _func) new EventFunctor< _type >( (_obj), (_func) )

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
	Camera*				m_pCamera;
	
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
	 *	Function:	SetCamera
	 *	Purpose:	Set the camera
	 **********************************/
	void SetCamera( Camera* _cam) { m_pCamera = _cam; }
	
	/**********************************
	 *	Function:	GetCamera
	 *	Purpose:	Get the camera
	 **********************************/
	Camera* GetCamera() { return m_pCamera; }
	
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
	 *	Function:	Add
	 *	Purpose:	Register a new entity
	 **********************************/
	void Add(PhyxObject* _object, unsigned _priority);
	
	/**********************************
	 *	Function:	Remove
	 *	Purpose:	Register a new entity
	 **********************************/
	void Remove(PhyxObject* _object);
	
	/*
	 *	Event Manager forwards
	 */
	
	/**********************************
	 *	Function:	RegisterForEvent
	 *	Purpose:	Forward a request for a new event to the event manager.
	 *	Params:
	 *		_id:		These should probably be defined in an enum somewhere to ensure not using the same number twice
	 *		_functor:	Functor pointing to the callback
	 *		_priority:	EP_LOW, EP_MEDIUM, EP_HIGH
	 **********************************/
	void RegisterForEvent(unsigned _id, BaseFunctor* _functor, EVENT_PRIORITY _priority);
	
	/**********************************
	 *	Function:	SendEvent
	 *	Purpose:	Forward a request for a new event to the event manager.
	 **********************************/
	void UnregisterForEvent(PhyxObject* _object);
	
	/**********************************
	 *	Function:	SendEvent
	 *	Purpose:	Forward a request for a new event to the event manager.
	 **********************************/
	void UnregisterForEvent(PhyxObject* _object, unsigned _id);
	
	/**********************************
	 *	Function:	SendEvent
	 *	Purpose:	Forward a request for a new event to the event manager.
	 **********************************/
	void SendEvent(unsigned _id, BaseEvent* _data = NULL, short _frameDelay = 0);
	
	/**********************************
	 *	Function:	SendSynchronousEvent
	 *	Purpose:	Forward a request for a new event to the event manager.
	 **********************************/
	void SendSynchronousEvent(unsigned _id, BaseEvent* _data = NULL);
	
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