/*
 *  DPad.h
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 3/5/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef DPad_H_
#define DPad_H_

#include "phyx/common/Globals.h"
#include "phyx/common/Functors.h"
#include "phyx/managers/EventManager.h"


#include "phyx/objects/Entity.h"
class DPad : public Entity
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	
	// The backdrop texture
	TextureHandle			m_thBackDrop;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	DPad();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~DPad();
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	void Update(float _delta);
	
	/**********************************
	 *	Function:	Render
	 **********************************/
	void Render(void);
	
	/**********************************
	 *	Function:	event handlers
	 **********************************/
	bool TouchesBegan(unsigned _event, BaseEvent* _data);
	bool TouchesMoved(unsigned _event, BaseEvent* _data);
	bool TouchesEnded(unsigned _event, BaseEvent* _data);
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif