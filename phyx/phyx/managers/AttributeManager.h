/*
 *  AttributeManager.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 4/9/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef AttributeManager_H_
#define AttributeManager_H_

#include <string>
#include <map>

#include "../common/Logger.h"

class PhyxObject;

#include "BaseManager.h"
class AttributeManager : public BaseManager
{
	friend class phyx;
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	typedef std::map< std::string, void* >		attrList;
	typedef std::map< PhyxObject*, attrList >	attrDatabase;
	
	attrDatabase								m_mAttrDatabase;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	AttributeManager();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~AttributeManager();
	
	/**********************************
	 *	Function:	Update
	 *	Purpose:	updates the manager
	 **********************************/
	void Update(float _delta);
	
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	
	/**********************************
	 *	Function:	SetAttr
	 *	Purpose:	Set the value of an attribute
	 *	Notes:		If this attribute doesn't exist it WILL be created.
	 **********************************/
	template <typename T>
	void SetAttr(PhyxObject* _obj, std::string& _attrName, T _attrValue)
	{
		if ( m_mAttrDatabase.find( _obj ) == m_mAttrDatabase.end() )
		{
			m_mAttrDatabase[_obj] = attrList();
		}
		
		if ( m_mAttrDatabase[_obj].find( _attrName ) == m_mAttrDatabase[_obj].end() )
		{
			m_mAttrDatabase[_obj][_attrName] = malloc( sizeof(T) );
		}
		
		*(T*)m_mAttrDatabase[_obj][_attrName] = _attrValue;
	}
	
	/**********************************
	 *	Function:	GetAttr
	 *	Purpose:	Return the value of an attribute
	 *	Notes:		Returns NULL if attr or obj doesn't exist in database.
	 **********************************/
	template <typename T>
	const T * const GetAttr(PhyxObject* _obj, std::string& _attrName)
	{
		if ( m_mAttrDatabase.find( _obj ) == m_mAttrDatabase.end() )
		{
			// log.msg( "No AttrTable for object: " + std::string(&_obj), log::ERROR )
			return NULL;
		}
		
		if ( m_mAttrDatabase[_obj].find( _attrName ) == m_mAttrDatabase[_obj].end() )
		{
			// log.msg( "Attribute " + _attrName + " is NULL for object: " + std::string(&_obj), log::ERROR )
			return NULL;
		}
		
		return (T*)(m_mAttrDatabase[_obj][_attrName]);
	}
	
	/**********************************
	 *	Function:	DelAttr
	 *	Purpose:	Delete an attribute
	 *	Notes:		If its the last attribute owned by this object it removes the object from the database.
	 **********************************/
	bool DelAttr(PhyxObject* _obj, std::string& _attrName);
	
	/**********************************
	 *	Function:	ClearObj
	 *	Purpose:	Clear all attributes for an obj.
	 **********************************/
	bool ClearObjAttrs(PhyxObject* _obj);
};

#endif