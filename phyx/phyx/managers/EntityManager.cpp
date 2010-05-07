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

#if (TARGET_IPHONE_SIMULATOR)
	#include "../common/Logger.h"
#endif

EntityManager::EntityManager() :
	BaseManager()
{
}

EntityManager::~EntityManager()
{
}

PhyxObject* EntityManager::operator[](unsigned _id)
{ 
#if (TARGET_IPHONE_SIMULATOR)
	if ( m_mEntities[ _id ] == NULL )
		logger.log( "Trying to access a deleted entity", WARNING );
#endif
	return m_mEntities[_id]; 
}

void EntityManager::RegisterEntity(PhyxObject* _object)
{
	m_mEntities[ _object->GetID() ] = _object;
}

void EntityManager::RemoveEntity(PhyxObject* _object)
{
	unsigned index = _object->GetID();
	delete m_mEntities[ index ];
	m_mEntities[ index ] = NULL;
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


























