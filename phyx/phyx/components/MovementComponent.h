/*
 *  MovementComponent.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef MovementComponent_H_
#define MovementComponent_H_

#include "../math/vec2.h"

#include "BaseComponent.h"
class MovementComponent : public BaseComponent
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	vec2		m_vDestination;
	vec2		m_vDirection;
	float		m_fVelocity;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	MovementComponent(Entity* _entity, float _velocity);
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~MovementComponent();
	
	/**********************************
	 *	Function:	Update
	 *	Purpose:	update movement
	 **********************************/
	void Update(float _delta);
	
	/**********************************
	 *	Function:	Render
	 *	Purpose:	Render
	 **********************************/
	void Render();
	
	/**********************************
	 *	Function:	ClearDestination
	 *	Purpose:	Clear the destination, cuaseing the controller to revert to a different form of movement
	 **********************************/
	void ClearDestination();
	
	/**********************************
	 *	Function:	mutators
	 **********************************/
	inline void SetVelocity(float _velocity)				{ m_fVelocity = _velocity; }
	inline void SetDestination(const vec2& _destination)	{ m_vDestination = _destination; }
	void SetDirection(vec2& _direction);
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif