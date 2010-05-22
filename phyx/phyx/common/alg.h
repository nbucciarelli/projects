/*
 *  alg.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/3/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef Alg_h_
#define Alg_h_

/****************************************
 *	Function:	_ButterflySwap
 *	Purpose:	Perform a butterfly swap on 2 ints.
 ****************************************/
#define _ButterflySwap(x, y)		(x) ^= (y); (y) ^= (x); (x) ^= (y)

/****************************************
 *	Function:	_LittleToBigEndianInt
 *	Purpose:	Convert a little ending int to a big endian int.
 ****************************************/
#define _LittleToBigEndianInt(n)	( n = ( ( (n & 0xFF) << 24) + ( (n & 0xFF00) << 8) + ( (n & 0xFF0000) >> 8) + ( (n >> 24) & 0xFF) ) )

/****************************************
 *	Function:	_GetFilePath
 *	Purpose:	retrieve a file path for a resource given an NSString object. (nil can be passed for ext?)
 ****************************************/
#define _GetFilePath(path, ext)			[ [NSBundle mainBundle] pathForResource: path ofType: ext ]

/****************************************
 *	Function:	_NSStrToCStr
 *	Purpose:	Convert a NSString object to a char*
 ****************************************/
#define _NSStrToCStr(str)			[str cStringUsingEncoding: 1]

/****************************************
 *	Function:	_CStrToNSStr
 *	Purpose:	Convert a char* to a NSString object
 ****************************************/
#define _CStrToNSStr(str)			[NSString stringWithUTF8String: str]

/****************************************
 *	Function:	_GetFilePathGivenCStr
 *	Purpose:	Retrieve a file path for a resource given a char*.
 *	Note:		Uses "nil" as second parameter, is this always acceptable?
 ****************************************/
#define _GetFilePathGivenCStr(str)	_NSStrToCStr( _GetFilePath( _CStrToNSStr( str ), nil ) )

/****************************************
 *	Function:	_Swap
 *	Purpose:	Swap two variables using a tmp.
 *	Note:		Requires operator= overload
 ****************************************/
template <typename T>
void _Swap(T& _a, T& _b)
{
	T tmp = _a;
	_a = _b;
	_b = tmp;
}

/****************************************
 *	Function:	_ShellSort
 *	Purpose:	shell sort an array of objects.
 *	Note:		To use on a vector call "_ShellSort(&TypeVector[0], TypeVector.length())"
 ****************************************/
template <typename T>
void _ShellSort(T* _arr, int _n)
{
	for (int offset = _n; offset > 0; (offset == 2) ? 1 : (int)(offset/2.2f))
	{
		for (int i = offset; i < _n; ++i)
		{
			T tmp = _arr[i];
			int j = i;
			while (j >= offset && tmp < _arr[j - offset])
			{
				_arr[j] = _arr[j - offset];
				j -= offset;
			}
			_arr[j] = tmp;
		}
	}
}

/****************************************
 *	Function:	_ShellSortp
 *	Purpose:	Shell sort an array of object pointers.
 *	Note:		To use on a vector call "_ShellSortp(&TypeVector[0], TypeVector.length())"
 *	Note:		I don't remember why this isn't the same as _ShellSort<Type*>(TypeArr, TypeArrLen).
 *				but I do remember needing this, did I just not think to do it with a pointer as the template type?
 ****************************************/
template <typename T>
void _ShellSortp(T** _arr, int _n)
{
	for (int offset = _n; offset > 0; offset = (offset == 2) ? 1 : (int)(offset/2.2f))
	{
		for (int i = offset; i < _n; ++i)
		{
			T* tmp = _arr[i];
			int j = i;
			while (j >= offset && (*tmp) < (*_arr[j - offset]))
			{
				_arr[j] = _arr[j - offset];
				j -= offset;
			}
			_arr[j] = tmp;
		}
	}
}

#endif
