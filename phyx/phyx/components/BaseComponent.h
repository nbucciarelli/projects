/*
 *  BaseComponent.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef BaseComponent_H_
#define BaseComponent_H_

class Entity;

#include "../objects/PhyxObject.h"
class BaseComponent : public PhyxObject
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	Entity*		m_pControlledEntity;
	
private:
	/*	Private Data Members	*/
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	BaseComponent(Entity* _entity);
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	virtual ~BaseComponent() = 0;
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	virtual void Update(float _delta) = 0;
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif