/*
 *  Camera.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 4/18/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef Camera_H_
#define Camera_H_

#include "../math/vec2.h"
#include "../math/rect.h"

class Entity;

#include "../objects/PhyxObject.h"
class Camera : public PhyxObject
{
public:
	/*	Public Data Members		*/
	Entity*		m_pEntity;
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	
	vec2	m_vPosition;
	rect	m_rCameraBounds;
	rect	m_rWorldBounds;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	Camera(Entity* _entity, rect _cameraBounds, rect _worldBounds);
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~Camera();
	
	/**********************************
	 *	Function:	Attach
	 *	Purpose:	Attach the camera to an entity
	 **********************************/
	void Attach( Entity* _entity );
	
	/**********************************
	 *	Function:	SetWorldBounds
	 *	Purpose:	Attach the camera to an entity
	 **********************************/
	void SetWorldBounds( rect& _worldBounds );
	
	/**********************************
	 *	Function:	Update
	 *	Purpose:	Attach the camera to an entity
	 **********************************/
	void Update(float _delta);
	
	/**********************************
	 *	Function:	GetPosition
	 *	Purpose:	Return the position
	 **********************************/
	vec2& GetPosition() { return m_vPosition; }
	
	/**********************************
	 *	Function:	GetWorldBounds
	 *	Purpose:	Return the world bounds
	 **********************************/
	rect& GetWorldBounds() { return m_rWorldBounds; }
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif