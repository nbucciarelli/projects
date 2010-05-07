/*
 *  DPad.cpp
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 3/5/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "DPad.h"

#include "phyx/managers/EventManager.h"
#include "phyx/components/RenderComponent.h"
#include "phyx/math/vec2.h"
#include "phyx/phyx.h"


DPad::DPad() :
	Entity()
{
	// Init render object
	m_vPosition = vec2( 50.0f, 320.0f - 50.0f );
	std::string scaleStr( "scale" );
	Phyx->SetAttr< vec2 >( this, scaleStr, vec2(4.0f, 4.0f) );
	Phyx->RegisterEntity( new RenderComponent( this, "dpad_backdrop.tga", 16, 16, true, 0 ) );
	
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









