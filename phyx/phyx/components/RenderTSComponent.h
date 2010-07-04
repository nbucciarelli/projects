/*
 *  RenderTSComponent.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 7/4/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef RenderTSComponent_H_
#define RenderTSComponent_H_

#include "../common/Globals.h"

#include "BaseComponent.h"
class RenderTSComponent : public BaseComponent
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	
	TextureHandle	m_thTextureHandle;
	int				m_nMapWidth;
	int				m_nMapHeight;
	int				m_nTileWidth;
	int				m_nTileHeight;
	int*			m_pnTiles;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	RenderTSComponent(const char* _filePath);
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~RenderTSComponent();
	
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