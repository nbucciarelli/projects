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

class BaseEvent;

#include "phyx/objects/Entity.h"
class DPad : public Entity
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	bool	m_bSelected;
	
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
	 *	Function:	event handlers
	 **********************************/
	bool OnTouchesBegan(BaseEvent* _data);
	bool OnTouchesMoved(BaseEvent* _data);
	bool OnTouchesEnded(BaseEvent* _data);
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif