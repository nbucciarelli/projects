/*
 *  GamePlayState.h
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef GamePlayState_H_
#define GamePlayState_H_

#include "phyx/managers/StateManager.h"
class GamePlayState : public BaseState
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
	GamePlayState();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~GamePlayState();
	
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