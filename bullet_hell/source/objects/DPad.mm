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

#include "../common/Globals.h"


DPad::DPad() :
	Entity()
{
	// Init render object
	m_vPosition = vec2( 50.0f, 320.0f - 50.0f );
	std::string scaleStr( "scale" );
	Phyx->SetAttr< vec2 >( this, scaleStr, vec2(4.0f, 4.0f) );
	Phyx->Add( new RenderComponent( this, "dpad_backdrop.tga", 16, 16, true ), OP_UI );
	
	Phyx->RegisterForEvent(TOUCHES_BEGAN, _NewEventFunctor(DPad, this, &DPad::TouchesBegan));
	Phyx->RegisterForEvent(TOUCHES_MOVED, _NewEventFunctor(DPad, this, &DPad::TouchesMoved));
	Phyx->RegisterForEvent(TOUCHES_ENDED, _NewEventFunctor(DPad, this, &DPad::TouchesEnded));
}

DPad::~DPad()
{
	Phyx->UnregisterForEvent( this );
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









