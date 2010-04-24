/*
 *  ComponentManager.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef ComponentManager_H_
#define ComponentManager_H_

#include <list>

#include "../components/BaseComponent.h"

#include "BaseManager.h"
class ComponentManager : public BaseManager
{
	friend class WorldManager;
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	std::list< BaseComponent* > m_lComponents;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	RegisterComponent
	 *	Purpose:	Add a new entity to the manager
	 **********************************/
	void RegisterComponent(BaseComponent* _component);
	
	/**********************************
	 *	Function:	UnregisterComponent
	 *	Purpose:	remove a component from the update loop
	 **********************************/
	void UnregisterComponent(BaseComponent* _component);
	
	/**********************************
	 *	Function:	Update
	 *	Purpose:	update all components
	 **********************************/
	void Update(float _delta);
	
	/**********************************
	 *	Function:	Render
	 *	Purpose:	render all components
	 **********************************/
	void Render();
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	ComponentManager();
	ComponentManager(const ComponentManager&);
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~ComponentManager();
};

#endif