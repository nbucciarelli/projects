/*
 *  vec4.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 5/26/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef VEC4_H_
#define VEC4_H_

struct vec4
{
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			float r, g, b, a;
		};
	};
	
	/*********************************
	 *	Function:	Constructor
	 *********************************/
	vec4()											: x(0.0f), y(0.0f), z(0.0f), w(0.0f)	{ }
	vec4(float _x, float _y, float _z, float _w)	: x(_x), y(_y), z(_z), w(_w)			{ }
	
	/*********************************
	 *	Function:	Some commonly used vectors.
	 ********************************/
	static vec4 empty()			{ return vec4(); }
	static vec4 red()			{ return vec4(1.0, 0.0, 0.0, 1.0); }
	static vec4 green()			{ return vec4(0.0, 1.0, 0.0, 1.0); }
	static vec4 blue()			{ return vec4(0.0, 0.0, 1.0, 1.0); }
	static vec4 black()			{ return vec4(0.0, 0.0, 0.0, 1.0); }
	static vec4 white()			{ return vec4(1.0, 1.0, 1.0, 1.0); }
	static vec4 transparent()	{ return vec4(0.0, 0.0, 0.0, 0.0); }
};

#endif