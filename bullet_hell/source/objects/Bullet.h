//
//  Bullet.h
//  bullet_hell
//
//  Created by jamby on 5/14/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#ifndef Bullet_H_
#define Bullet_H_

class BaseEvent;

#include "phyx/objects/Entity.h"

class Bullet : public Entity
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	int m_nDamage;
	float m_fLifetime;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	Bullet();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~Bullet();
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	void Update(float _delta);
	
	/**********************************
	 *	Function:	Accessors
	 **********************************/
	int GetDamage(void) { return m_nDamage; }
	float GetLifetime(void) { return m_fLifetime; }
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	/**********************************
	 *	Function:	Mutators
	 **********************************/
	void SetDamage(int nDamage) { m_nDamage = nDamage; }
	void SetLifetime(float fLifetime) { m_fLifetime = fLifetime; }
};

#endif