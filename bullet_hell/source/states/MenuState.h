/*
 *  MenuState.h
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef MenuState_H_
#define MenuState_H_

#include "phyx/common/Globals.h"

#include "phyx/managers/StateManager.h"
class MenuState : public BaseState
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	TextureHandle			m_thBackGround;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	MenuState();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~MenuState();
	
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