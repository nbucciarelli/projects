/*
 *  Avatar.h
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef Avatar_H_
#define Avatar_H_

class BaseEvent;
class Weapon;

#include "phyx/objects/Entity.h"

class Avatar : public Entity
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	Weapon* m_pWeapon;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	Avatar();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~Avatar();
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	void Update(float _delta);
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif