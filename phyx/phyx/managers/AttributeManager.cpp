/*
 *  AttributeManager.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 4/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "AttributeManager.h"

AttributeManager::AttributeManager()
{
}

AttributeManager::~AttributeManager()
{
	for ( attrDatabase::iterator i = m_mAttrDatabase.begin(); i != m_mAttrDatabase.end(); ++i )
	{
		for ( attrList::iterator j = (*i).second.begin(); j != (*i).second.end(); ++j )
		{
			free( (*j).second );
		}
	}
}

void AttributeManager::Update(float _delta)
{
}

bool AttributeManager::DelAttr(PhyxObject* _obj, std::string& _attrName)
{
	if ( m_mAttrDatabase.find( _obj ) == m_mAttrDatabase.end() )
	{
		logger->log( "Failed attempt to delete invalid attribute in AttributeManager", WARNING ); // "No AttrTable for object at: %i" + _obj ).c_str() , WARNING );
		return false;
	}
	
	attrList::iterator iter = m_mAttrDatabase[_obj].find( _attrName );
	if ( iter == m_mAttrDatabase[_obj].end() )
	{
		// log.msg( "Attribute " + _attrName + " is NULL for object: " + std::string(&_obj), log::WARNING )
		return false;
	}
	
	free( (*iter).second );
	m_mAttrDatabase[_obj].erase( iter );
	
	if ( m_mAttrDatabase[_obj].empty() )
	{
		m_mAttrDatabase.erase( m_mAttrDatabase.find( _obj ) );
	}
	
	// Success.
	return true;
}

bool AttributeManager::ClearObjAttrs(PhyxObject* _obj)
{
	// Find the object
	attrDatabase::iterator iter = m_mAttrDatabase.find( _obj );
	if ( iter == m_mAttrDatabase.end() )
	{
		// log.msg( "Object " + _obj + " does not exist in database.", log::WARNING )
		return false;
	}
	
	// free all dynamic memory
	for ( attrList::iterator i = (*iter).second.begin(); i != (*iter).second.end(); ++i )
	{
		free( (*i).second );
	}
	
	// erase objects list
	m_mAttrDatabase.erase( iter );
	
	// Success.
	return true;
}



