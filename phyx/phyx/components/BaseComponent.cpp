/*
 *  BaseComponent.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "BaseComponent.h"

BaseComponent::BaseComponent(Entity* _entity) :
	m_pControlledEntity( _entity )
{
}

BaseComponent::~BaseComponent()
{
}

void BaseComponent::Update(float _delta)
{
}

void BaseComponent::Render()
{
}