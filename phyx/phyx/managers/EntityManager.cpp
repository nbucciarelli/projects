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

void EntityManager::RegisterEntity(PhyxObject* _object, unsigned _priority)
{
	m_mEntities[ _object->GetID() ] = _object;
	
	while( m_lUpdateLists.size() <= _priority )
		m_lUpdateLists.push_back( std::list< unsigned >() );
	
	m_lUpdateLists[ _priority ].push_back( _object->GetID() );
}

void EntityManager::RemoveEntity(PhyxObject* _object)
{
	unsigned index = _object->GetID();
	delete m_mEntities[ index ];
	m_mEntities[ index ] = NULL;
}

void EntityManager::Update(float _delta)
{
	for (std::list< unsigned >::iterator iter = m_lUpdateLists[0].begin(); iter != m_lUpdateLists[0].end(); ++iter)
	{
		m_mEntities[ *iter ]->Update( _delta );
	}
}

void EntityManager::Render(float _delta)
{
	for (std::vector< std::list< unsigned > >::iterator listIter = (++m_lUpdateLists.begin()); listIter != m_lUpdateLists.end(); ++listIter)
	{
		for (std::list< unsigned >::iterator iter = (*listIter).begin(); iter != (*listIter).end(); ++iter)
		{
			m_mEntities[ *iter ]->Update( _delta );
		}
	}
}


























