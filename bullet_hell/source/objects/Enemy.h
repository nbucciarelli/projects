/*
 *  Enemy.h
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef Enemy_H_
#define Enemy_H_

#include "phyx/objects/Entity.h"
class Enemy : public Entity
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
	Enemy();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~Enemy();
	
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