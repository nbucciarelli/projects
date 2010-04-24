/*
 *  phyxobject.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/6/10.
 *  Copyright 2010 Kyle Rothermel. All rights reserved.
 *
 */

#ifndef PhyxObject_H_
#define PhyxObject_H_


class PhyxObject
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	unsigned	m_id;
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	PhyxObject();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	virtual ~PhyxObject();
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	virtual void Update(float _delta) = 0;
	
	/**********************************
	 *	Function:	Render
	 *	TODO: Rendering should all be handled by the renderer.
	 **********************************/
	virtual void Render() = 0;
	
	/**********************************
	 *	Function:	Accessors
	 **********************************/
	inline unsigned GetID()		{ return m_id; }
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif