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
	bool TouchesBegan(unsigned _event, BaseEvent* _data);
	bool TouchesMoved(unsigned _event, BaseEvent* _data);
	bool TouchesEnded(unsigned _event, BaseEvent* _data);
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif