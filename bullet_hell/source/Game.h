/*
 *  Game.h
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef Game_H_
#define Game_H_

class StateManager;

class Game
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	
	// Our game manager
	static Game			sm_Instance;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	GetInstance
	 **********************************/
	static Game* GetInstance() { return &sm_Instance; }
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	Game();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~Game();
	
	/**********************************
	 *	Function:	Init
	 **********************************/
	void Init();
	
	/**********************************
	 *	Function:	Shutdown
	 **********************************/
	void Shutdown();
	
	/**********************************
	 *	Function:	Heartbeat
	 **********************************/
	void Heartbeat();
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	void Update();
	
	/**********************************
	 *	Function:	Render
	 **********************************/
	void Render();
};

static Game * const _pGame = Game::GetInstance();

#endif