/*
 *  vec2.cpp
 *  Ants
 *
 *  Created by Kyle Rothermel on 4/11/09.
 *  Copyright 2009 Kyle Rothermel. All rights reserved.
 *
 */

#include "vec2.h"

#include <cmath>
#include <stdlib.h>

#include "PhyxMath.h"
#include "rect.h"

/*	Public Functions	*/
float vec2::magnitude() const
{
	return sqrtf((x * x) + (y * y));
}

float vec2::magnitudeSquared() const
{
	return ((x * x) + (y * y));
}

float vec2::dot(const vec2& _v) const
{
	return ((x * _v.x) + (y * _v.y));
}

vec2& vec2::normalize()
{
	float l = magnitude();
	
	x /= l;
	y /= l;
	
	return *this;
}

vec2& vec2::rotate(float _rads)
{
	float c = cos(_rads);
	float s = sin(_rads);
	
	x = (c * x) + (s * y);
	y = (-s * x) + (c * y);
	
	return *this;
}

float vec2::angleBetween(const vec2& _v) const
{
	float l = magnitude() * _v.magnitude();
	
	// avoid divide by 0.
	if (l == 0.0f) return 0.0f;
	
	float rads = acosf(dot(_v) / l);
	if (x > _v.x)
		rads = (2 * _PI) + (rads * -1.0f);
	
	return rads;
}

bool vec2::inRect(const rect* _r) const
{
	if ( x < _r->right && x > _r->left && y < _r->bottom && y > _r->top )
		return true;
	return false;
}

bool vec2::inCircle(const vec2& _center, float _radius) const
{
	if ( (*this - _center).magnitudeSquared() < _radius * _radius )
		return true;
	return false;
}

bool vec2::equals(const vec2& _v, float _tolerence) const
{
	return (abs(x - _v.x) < _tolerence && abs(y - _v.y) < _tolerence);
}

/*	Protected Functions	*/

/*	Private Functions	*/