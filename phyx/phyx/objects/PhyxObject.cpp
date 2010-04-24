/*
 *  phyxobject.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/6/10.
 *  Copyright 2010 Kyle Rothermel. All rights reserved.
 *
 */

#include "PhyxObject.h"

PhyxObject::PhyxObject()
{
	static unsigned objectCount = 0;
	m_id = objectCount;
	objectCount++;
}

PhyxObject::~PhyxObject()
{
	
}

void PhyxObject::Update( float _delta )
{
}

void PhyxObject::Render()
{
}