/*
 *  PhyxMath.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 3/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _phyxmath_h_
#define _phyxmath_h_


// Mathatical PI
#ifndef _PI
#define _PI 3.14159265f
#endif

// _PI * 2
#ifndef _2PI
#define _2PI _PI * 2
#endif

// Convert from Deg to Rad
#ifndef _DegToRad
#define _DegToRad(_deg)		((_deg)*(_PI/180.0f))
#endif

// Convert from Rad to Deg
#ifndef _RadToDeg
#define _RadToDeg(_rad)		((_rad)*(180.0f/_PI))
#endif

// Calculate a random float
#ifndef _RandFloat
#define _RandFloat(min, max) ((rand()/(float)RAND_MAX) * ((max) - (min)) + (min))
#endif

// Interpolate a float
inline float lerpf(float _f1, float _f2, float _lambda) { return (_f1 + ((_f2 - _f1) * _lambda)); }

// Check if 2 floats are equal
inline bool floatsAreEqual(float _f1, float _f2, float _epsilon) { return ((_f1 < _f2 + _epsilon) && (_f1 > _f2 - _epsilon)); }


#endif