/*
 *  phyxCommon.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _phyxCommon_h_
#define _phyxCommon_h_

#include <OpenGLES/EAGL.h>
#include <OpenGLES/ES1/gl.h>
/**********************************
 *	Function:	Init/ShutdownPhyx
 *	Purpose:	Init and shutdown the phyx engine, should be called at game launch/close
 **********************************/
void InitPhyx(GLuint _viewRenderBuffer, GLuint _viewFrameBuffer, GLint _backingWidth, GLint _backingHeight, EAGLContext* _context);
void ShutdownPhyx();

#endif