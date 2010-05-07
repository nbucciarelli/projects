/*
 *  Entity.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef Entity_H_
#define Entity_H_

#include "../math/vec2.h"

#include "PhyxObject.h"
class Entity : public PhyxObject
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	vec2							m_vPosition;
	
private:
	/*	Private Data Members	*/
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	Entity();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	virtual ~Entity() = 0;
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	virtual void Update(float _delta) = 0;
	
	/**********************************
	 *	Function:	Accessors
	 **********************************/
	inline const vec2& GetPosition()	{ return m_vPosition; }
	
	/**********************************
	 *	Function:	mutators
	 **********************************/
	inline const void SetPosition(const vec2& _pos)		{ m_vPosition = _pos; }
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif