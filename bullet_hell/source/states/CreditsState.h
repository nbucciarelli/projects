/*
 *  CreditsState.h
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef CreditsState_H_
#define CreditsState_H_

#include "phyx/managers/StateManager.h"
class CreditsState : public BaseState
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	CreditsState();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~CreditsState();
	
	/**********************************
	 *	Function:	Enter
	 **********************************/
	void Enter();
	
	/**********************************
	 *	Function:	Exit
	 **********************************/
	void Exit();
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	void Update(float _delta);
	
	/**********************************
	 *	Function:	Render
	 **********************************/
	void Render();
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif