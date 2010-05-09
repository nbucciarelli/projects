/*
 *  RenderComponent.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 5/2/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef RenderComponent_H_
#define RenderComponent_H_

#include <string>

#include "../common/Globals.h"

#include "BaseComponent.h"
class RenderComponent : public BaseComponent
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	
	TextureHandle	m_thTextureHandle;
	bool			m_bDrawCentered;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	RenderComponent(Entity* _controlledEntity, const char* _textureName, short _texWidth, short _texHeight, bool _drawCentered);
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~RenderComponent();
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	void Update(float _delta);
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif