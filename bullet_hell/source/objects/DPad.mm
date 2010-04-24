/*
 *  DPad.cpp
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 3/5/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "DPad.h"

#include "phyx/wrappers/Renderer.h"
#include "phyx/math/vec2.h"
#include "phyx/phyx.h"


DPad::DPad() :
	Entity()
{
	m_thBackDrop = _pRenderer->LoadTexture("dpad_backdrop.tga", 16, 16);
	
	_RegisterForEvent( DPad, this, &DPad::TouchesBegan, TOUCHES_BEGAN );
	_RegisterForEvent( DPad, this, &DPad::TouchesMoved, TOUCHES_MOVED );
	_RegisterForEvent( DPad, this, &DPad::TouchesEnded, TOUCHES_ENDED );
}

DPad::~DPad()
{
	_UnregisterForEvent( this );
}

void DPad::Update(float _delta)
{
}

void DPad::Render(void)
{
	_pRenderer->DrawTexture(m_thBackDrop, vec2(50, 320 - 50), true, vec2(4.0, 4.0));
}

bool DPad::TouchesBegan(unsigned _event, BaseEvent* _data)
{
	return true;
}

bool DPad::TouchesMoved(unsigned _event, BaseEvent* _data)
{
	return true;
}

bool DPad::TouchesEnded(unsigned _event, BaseEvent* _data)
{
	return true;
}









