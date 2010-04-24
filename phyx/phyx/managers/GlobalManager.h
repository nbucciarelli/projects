/*
 *  GlobalManager.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef GlobalManager_H_
#define GlobalManager_H_

#include <string>
#include <map>

#include "BaseManager.h"
class GlobalManager : public BaseManager
{
	friend class WorldManager;
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	std::map<std::string, bool>			m_mGlobalBools;
	std::map<std::string, int>			m_mGlobalInts;
	std::map<std::string, float>		m_mGlobalFloats;
	std::map<std::string, std::string>	m_mGlobalStrings;
	
	
public:
	/*	Public Functions		*/
	
	/**********************************
	 *	Function:	Update
	 **********************************/
	void Update(float _delta) {}
	
	/**********************************
	 *	Function:	RegisterGlobal*
	 *	Purpose:	Register a new global
	 **********************************/
	void RegisterGlobal(std::string& _key, bool _value);
	void RegisterGlobal(std::string& _key, int _value);
	void RegisterGlobal(std::string& _key, float _value);
	void RegisterGlobal(std::string& _key, std::string& _value);
	
	/**********************************
	 *	Function:	GetGlobal*
	 *	Purpose:	Retrieve a global from the manager
	 **********************************/
	bool GetGlobalBool(std::string& _key);
	int GetGlobalInt(std::string& _key);
	float GetGlobalFloat(std::string& _key);
	std::string& GetGlobalString(std::string& _key);
	
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	
	/**********************************
	 *	Function:	Constructor
	 **********************************/
	GlobalManager();
	GlobalManager(const GlobalManager&);
	
	/**********************************
	 *	Function:	Destructor
	 **********************************/
	~GlobalManager();
};

#endif