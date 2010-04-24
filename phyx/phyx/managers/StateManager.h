/*
 *  StateManager.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef StateManager_H_
#define StateManager_H_

#include <list>

#include "BaseManager.h"

class BaseState
{
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	BaseState();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	virtual ~BaseState() = 0;
	
	/**********************************
	 *	Function:	Enter
	 **********************************/
	virtual void Enter() = 0;
	
	
	/**********************************
	 *	Function:	Exit
	 **********************************/
	virtual void Exit() = 0;
	
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	virtual void Update(float _delta) = 0;
	
	/**********************************
	 *	Function:	Render
	 **********************************/
	virtual void Render() = 0;
	
	
};

class StateManager : public BaseManager
{
	friend class phyx;
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	std::list< BaseState* >		m_lStates;
	
public:
	/*	Public Functions		*/
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	StateManager();
	StateManager(const StateManager&);
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~StateManager();
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	void Update(float _delta);
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	void Render();
	
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
	void Clear();
};

#endif