/*
 *  EntityManager.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef EntityManager_H_
#define EntityManager_H_

#include <map>

class PhyxObject;

#include "BaseManager.h"
class EntityManager : public BaseManager
{
	friend class phyx;
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	std::map< unsigned, PhyxObject* > m_mEntities;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Operator overloads
	 **********************************/
	inline PhyxObject* operator[](unsigned _id)	{ return m_mEntities[_id]; }
	
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	EntityManager();
	EntityManager(const EntityManager&);
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~EntityManager();
	
	/**********************************
	 *	Function:	RegisterEntity
	 *	Purpose:	Add a new entity to the manager
	 **********************************/
	void RegisterEntity(PhyxObject* _entity);
	
	/**********************************
	 *	Function:	Update
	 *	Purpose:	Update the manager
	 **********************************/
	void Update(float _delta);
	
	/**********************************
	 *	Function:	Render
	 *	Purpose:	Render all entities
	 **********************************/
	void Render();
};


#endif