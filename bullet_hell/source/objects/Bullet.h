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
class Weapon;

#include "phyx/objects/Entity.h"

class Bullet : public Entity
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	Weapon* m_pWeaponParent;
	int m_nDamage;
	float m_fLifetime;
	vec2 m_vDirection;
	bool m_bShot;
	bool m_bBeenReset;
	
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
	 *	Function:	Mutators
	 **********************************/
	void SetDamage(int nDamage) { m_nDamage = nDamage; }
	void SetLifetime(float fLifetime) { m_fLifetime = fLifetime; }
	void SetDireciton(vec2 vDirection) { m_vDirection = vDirection; }
	void SetBeingShot(bool bShot) { m_bShot = bShot; }
	
	/**********************************
	 *	Function:	Accessors
	 **********************************/
	int GetDamage(void) { return m_nDamage; }
	float GetLifetime(void) { return m_fLifetime; }
	vec2 GetDirection(void) { return m_vDirection; }
	bool GetBeingShot(void) { return m_bShot; }
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	void ResetBullet(void);
};

#endif