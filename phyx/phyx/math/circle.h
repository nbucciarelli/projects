/*
 *  circle.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 5/15/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef circle_H_
#define circle_H_

#include "vec2.h"

struct circle
{
	vec2 center;
	float radius;
	
	/*********************************
	 *	Function:	Constructors
	 *********************************/
	circle()								: center(), radius(0.0f)				{ }
	circle(vec2& _center, float _radius)	: center( _center ), radius( _radius )	{ }
	
	bool containsPoint( const vec2* _point) const;
};

#endif