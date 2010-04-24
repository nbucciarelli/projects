/*
 *  MovementComponent.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "MovementComponent.h"

#include "../objects/Entity.h"

MovementComponent::MovementComponent(Entity* _entity, float _velocity) :
	BaseComponent( _entity ),
	m_fVelocity( _velocity )
{
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::Update(float _delta)
{
	if ( m_vDestination != vec2::empty() )
	{
		m_vDirection = ( m_vDestination - m_pControlledEntity->GetPosition() ).normalize();
	}
	m_pControlledEntity->SetPosition( m_pControlledEntity->GetPosition() + ( m_vDirection * m_fVelocity ) );
}

void MovementComponent::Render()
{
}

void MovementComponent::SetDirection(vec2& _direction)
{
	m_vDirection = _direction.normalize();
}


