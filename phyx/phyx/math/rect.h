/*
 *  rect.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/3/10.
 *  Copyright 2010 Kyle Rothermel. All rights reserved.
 *
 */


#ifndef rect_H_
#define rect_H_

struct vec2;

struct rect
{
	float left, bottom, right, top;
	
	/*********************************
	 *	Function:	Constructors
	 *********************************/
	rect()														: left(0.0f), top(0.0f), right(0.0f), bottom(0.0f) {}
	rect(float _left, float _bottom, float _right, float _top)	: left(_left), bottom(_bottom), right(_right), top(_top) {}
	
	/*********************************
	 *	Function:	Some commonly used rects.
	 ********************************/
	static rect emptyRect()			{ return rect(); }
	
	/*********************************
	 *	Function:	width/height
	 *	Purpose:	return the width/height of the rect
	 *********************************/
	inline float width() const	{ return right - left; }
	inline float height() const	{ return top - bottom; }
	
	/*********************************
	 *	Function:	containsPoint
	 *	Created:	[KR] May 15, 2010
	 *	Purpose:	Determine if a vec2 is in a rect.
	 *	Return:		true if inside rect false otherwise.
	 *********************************/
	bool containsPoint(const vec2* _point) const;
};

inline bool operator==(const rect& _r1, const rect&  _r2)	
{ return (_r1.left == _r2.left && _r1.bottom == _r2.bottom && _r1.right == _r2.right && _r1.top == _r2.top); }
inline bool operator!=(const rect& _r1, const rect&  _r2)	{ return !(_r1 == _r2); }

#endif
































