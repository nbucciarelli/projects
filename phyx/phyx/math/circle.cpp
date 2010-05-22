/*
 *  circle.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 5/15/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "circle.h"


bool circle::containsPoint( const vec2* _point) const
{
	return _point->inCircle( this );
}