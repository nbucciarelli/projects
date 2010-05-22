/*
 *  rect.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/3/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "rect.h"

#include "vec2.h"

bool rect::containsPoint(const vec2* _v) const
{
	return _v->inRect( this );
}