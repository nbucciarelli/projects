/*
 *  vec2.h
 *  Ants
 *
 *  Created by Kyle Rothermel on 4/11/09.
 *  Copyright 2009 Kyle Rothermel. All rights reserved.
 *
 */
#ifndef VEC_2_
#define VEC_2_
 
struct vec2
{
	float x, y;
	
	/*********************************
	 *	Function:	Constructor
	 *********************************/
	vec2()						: x(0.0f), y(0.0f) { }
	vec2(float _x, float _y)	: x(_x), y(_y) { }
	
	/*********************************
	 *	Function:	Some commonly used vectors.
	 ********************************/
	static vec2 empty()							{ return vec2(0.0f, 0.0f); }
	static vec2 upVec()							{ return vec2(0.0f, -1.0f); }
	static vec2 downVec()						{ return vec2(0.0f, 1.0f); }
	static vec2 leftVec()						{ return vec2(-1.0f, 0.0f); }
	static vec2 rightVec()						{ return vec2(1.0f, 0.0f); }
	
	/*********************************
	 *	Function:	magnitude
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Return the length of the vector.
	 *				This uses sqrt() so avoid when possible.
	 *********************************/
	float magnitude() const;
	
	/*********************************
	 *	Function:	magnitudeSquared
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Return the squared length of the vector.
	 *********************************/
	float magnitudeSquared() const;
	
	/*********************************
	 *	Function:	dot
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Return the dot product of two vectors.
	 *********************************/
	float dot(const vec2& _v) const;
	
	/*********************************
	 *	Function:	normalize
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	normalize the vector, settings its magnitude to 1.0f.
	 *********************************/
	vec2& normalize();
	
	/*********************************
	 *	Function:	rotate
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	rotate a vector by a given amount.
	 *	_rads:		Amount to rotate by in radians.
	 *********************************/
	vec2& rotate(float _rads);
	
	/*********************************
	 *	Function:	angleBetween
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Find the angle between two vectors.
	 *	Return:		The angle in radians.
	 *********************************/
	float angleBetween(const vec2& _v) const;
	
	/*********************************
	 *	Function:	equals
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Determine if 2 vec2's are equal given a tolerence.
	 *	Return:		The angle in radians.
	 *********************************/
	bool equals(const vec2& _v, float _tolerence) const;
};

/*********************************
 *	Function:	Operator Overloads
 *	Created:	[KR] April 11, 2009
 *********************************/
inline vec2 operator-(const vec2& _v1, const vec2& _v2)		{ return vec2(_v1.x - _v2.x, _v1.y - _v2.y); }
inline vec2& operator-=(vec2& _v1, const vec2& _v2)			{ _v1.x -= _v2.x; _v1.y -= _v2.y; return _v1; }
inline vec2 operator+(const vec2& _v1, const vec2& _v2)		{ return vec2(_v1.x + _v2.x, _v1.y + _v2.y); }
inline vec2& operator+=(vec2& _v1, const vec2& _v2)			{ _v1.x += _v2.x; _v1.y += _v2.y; return _v1; }
inline vec2 operator*(const vec2& _v1, float _f)			{ return vec2(_v1.x * _f, _v1.y * _f); }
inline vec2& operator*=(vec2& _v1, float _f)				{ _v1.x *= _f; _v1.y *= _f; return _v1; }
inline vec2 operator/(const vec2& _v1, float _f)			{ return vec2(_v1.x / _f, _v1.y / _f); }
inline vec2& operator/=(vec2& _v1, float _f)				{ _v1.x /= _f; _v1.y /= _f; return _v1; }
inline bool operator==(const vec2& _v1, const vec2&  _v2)	{ return (_v1.x == _v2.x && _v1.y == _v2.y); }
inline bool operator!=(const vec2& _v1, const vec2&  _v2)	{ return !(_v1 == _v2); }

#endif


