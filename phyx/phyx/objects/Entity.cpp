/*
 *  Entity.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Entity.h"

#include "../common/Functors.h"

Entity::Entity() :
	PhyxObject(),
	m_vPosition()
{
}

Entity::~Entity()
{
}

void Entity::Update(float _delta)
{
}