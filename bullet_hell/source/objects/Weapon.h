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

enum eWeaponType { PISTOL, SHOTGUN, BURST_RIFLE, AUTO_RIFLE };

class Weapon : public Entity
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	int m_nType;
	float m_fROF;
	
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
	int GetType(void) { return m_nType; }
	float GetROF(void) { return m_fROF; }
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	/**********************************
	 *	Function:	Mutators
	 **********************************/
	void SetType(int nType) { m_nType = nType; }
	void SetROF(float fROF) { m_fROF = fROF; }
};

#endif
