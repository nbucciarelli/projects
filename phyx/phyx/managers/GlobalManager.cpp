/*
 *  GlobalManager.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/7/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "GlobalManager.h"

GlobalManager::GlobalManager() :
	BaseManager()
{
}

GlobalManager::~GlobalManager()
{
}

void GlobalManager::RegisterGlobal(std::string& _key, bool _value)
{
	m_mGlobalBools[_key] = _value;
}

void GlobalManager::RegisterGlobal(std::string& _key, int _value)
{
	m_mGlobalInts[_key] = _value;
}

void GlobalManager::RegisterGlobal(std::string& _key, float _value)
{
	m_mGlobalFloats[_key] = _value;
}

void GlobalManager::RegisterGlobal(std::string& _key, std::string& _value)
{
	m_mGlobalStrings[_key] = _value;
}

bool GlobalManager::GetGlobalBool(std::string& _key)
{
	return m_mGlobalBools[_key];
}

int GlobalManager::GetGlobalInt(std::string& _key)
{
	return m_mGlobalInts[_key];
}

float GlobalManager::GetGlobalFloat(std::string& _key)
{
	return m_mGlobalFloats[_key];
}

std::string& GlobalManager::GetGlobalString(std::string& _key)
{
	return m_mGlobalStrings[_key];
}



