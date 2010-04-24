/*
 *  phyxCommon.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "phyxCommon.h"

#include "../phyx.h"
#include "../wrappers/Renderer.h"


void InitPhyx(GLuint _viewRenderBuffer, GLuint _viewFrameBuffer, GLint _backingWidth, GLint _backingHeight, EAGLContext* _context)
{
	_pRenderer->Init(_viewRenderBuffer, _viewFrameBuffer, _backingWidth, _backingHeight, _context);
	Phyx->Initialize();
}

void ShutdownPhyx()
{
	Phyx->Shutdown();
}






