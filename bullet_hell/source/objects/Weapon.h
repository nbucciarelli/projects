//
//  Weapon.h
//  bullet_hell
//
//  Created by jamby on 5/14/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#ifndef Weapon_H_
#define Weapon_H_

#include "phyx/objects/Entity.h"

class Weapon : public Entity
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	float m_fLifetime;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	Weapon();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~Weapon();
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	void Update(float _delta);
	
	/**********************************
	 *	Function:	Accessors
	 **********************************/
	float GetLifeTime(void) { return m_fLifetime; }
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	/**********************************
	 *	Function:	Mutators
	 **********************************/
	void SetLifeTime(float fLifeTime) { m_fLifetime = fLifeTime; }
};

#endif
