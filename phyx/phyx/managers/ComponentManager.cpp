/*
 *  ComponentManager.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "ComponentManager.h"

ComponentManager::ComponentManager() :
	BaseManager()
{
}

ComponentManager::~ComponentManager()
{
}


void ComponentManager::RegisterComponent(BaseComponent* _component)
{
	m_lComponents.push_back( _component );
}

void ComponentManager::UnregisterComponent(BaseComponent* _component)
{
	for( std::list< BaseComponent* >::iterator iter = m_lComponents.begin(); iter != m_lComponents.end(); ++iter )
	{
		if ( _component == (*iter) )
		{
			m_lComponents.erase( iter );
			return;
		}
	}
}

void ComponentManager::Update(float _delta)
{
	for ( std::list< BaseComponent* >::iterator iter = m_lComponents.begin(); iter != m_lComponents.end(); ++iter )
	{
		(*iter)->Update( _delta );
	}
}

void ComponentManager::Render()
{
	for ( std::list< BaseComponent* >::iterator iter = m_lComponents.begin(); iter != m_lComponents.end(); ++iter )
	{
		(*iter)->Render();
	}
}






