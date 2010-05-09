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
#include "../common/EventIds.h"

#define MAX_DISTANCE 32
#define HOME_POSITION vec2( 50.0f, 320.0f - 50.0f )

DPad::DPad() :
	Entity(),
	m_bSelected( false )
{
	// Init render object
	m_vPosition = vec2( HOME_POSITION );
	std::string scaleStr( "scale" );
	Phyx->SetAttr< vec2 >( this, scaleStr, vec2( 4.0f, 4.0f ) );
	Phyx->Add( new RenderComponent( this, "dpad_backdrop.tga", 16, 16, true ), OP_UI );
	
	Phyx->RegisterForEvent( TOUCHES_BEGAN, _NewEventFunctor( DPad, this, &DPad::TouchesBegan ) );
	Phyx->RegisterForEvent( TOUCHES_MOVED, _NewEventFunctor( DPad, this, &DPad::TouchesMoved ) );
	Phyx->RegisterForEvent( TOUCHES_ENDED, _NewEventFunctor( DPad, this, &DPad::TouchesEnded ) );
}

DPad::~DPad()
{
	Phyx->UnregisterForEvent( this );
}

void DPad::Update(float _delta)
{
	if ( m_bSelected )
	{
		vec2 offset = m_vPosition - HOME_POSITION;
		
		offset.x /= MAX_DISTANCE;
		offset.y /= MAX_DISTANCE;
		
		Phyx->SendEvent( DPAD_MOVED, new Vec2Event( offset ) );
	}
}

bool DPad::TouchesBegan(unsigned _event, BaseEvent* _data)
{
	if ( ((Vec2Event*)_data)->data.inCircle( m_vPosition, MAX_DISTANCE ) )
	{
		m_vPosition = ((Vec2Event*)_data)->data;
		m_bSelected = true;
		
		// limit the distance
		if ( (m_vPosition - HOME_POSITION).magnitudeSquared() > MAX_DISTANCE * MAX_DISTANCE )
		{
			m_vPosition = HOME_POSITION + (m_vPosition - HOME_POSITION).normalize() * MAX_DISTANCE;
		}
		
		return false;
	}
	return true;
}

bool DPad::TouchesMoved(unsigned _event, BaseEvent* _data)
{
	if ( m_bSelected )
	{
		m_vPosition = ((Vec2Event*)_data)->data;
		
		// limit the distance
		if ( (m_vPosition - HOME_POSITION).magnitudeSquared() > MAX_DISTANCE * MAX_DISTANCE )
		{
			m_vPosition = HOME_POSITION + (m_vPosition - HOME_POSITION).normalize() * MAX_DISTANCE;
		}
		
	}
	return true;
}

bool DPad::TouchesEnded(unsigned _event, BaseEvent* _data)
{
	if ( m_bSelected )
	{
		m_vPosition = HOME_POSITION;
		m_bSelected = false;
	}
	return true;
}









