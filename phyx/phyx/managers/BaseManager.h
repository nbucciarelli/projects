/*
 *  BaseManager.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef BaseManager_H_
#define BaseManager_H_

class BaseManager
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	BaseManager();
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	virtual ~BaseManager() = 0;
	
	/**********************************
	 *	Function:	Update
	 *	Purpose:	updates the manager
	 **********************************/
	virtual void Update(float _delta) = 0;
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
};

#endif