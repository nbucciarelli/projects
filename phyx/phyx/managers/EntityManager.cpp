/*
 *  EntityManager.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "EntityManager.h"

#include "../objects/PhyxObject.h"

EntityManager::EntityManager() :
	BaseManager()
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::RegisterEntity(PhyxObject* _entity)
{
	m_mEntities[ _entity->GetID() ] = _entity;
}

void EntityManager::Update(float _delta)
{
	for (std::map< unsigned, PhyxObject* >::iterator iter = m_mEntities.begin(); iter != m_mEntities.end(); ++iter)
	{
		(*iter).second->Update( _delta );
	}
}

void EntityManager::Render()
{
	for (std::map< unsigned, PhyxObject* >::iterator iter = m_mEntities.begin(); iter != m_mEntities.end(); ++iter)
	{
		(*iter).second->Render();
	}
}


























