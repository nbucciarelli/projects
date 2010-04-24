/*
 *  StateManager.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "StateManager.h"

BaseState::BaseState() { }
BaseState::~BaseState() { }

StateManager::StateManager()
{
}

StateManager::~StateManager()
{
	Clear();
}

void StateManager::ChangeState(BaseState* _state)
{
	Clear();
	PushState(_state);
}

void StateManager::PushState(BaseState* _state)
{
	m_lStates.push_front(_state);
	_state->Enter();
}

void StateManager::PopState()
{
	if (!m_lStates.empty())
	{
		m_lStates.front()->Exit();
		delete m_lStates.front();
		m_lStates.pop_front();
	}
}

void StateManager::Clear()
{
	while (!m_lStates.empty())
		PopState();
}

void StateManager::Update(float _delta)
{
	if (!m_lStates.empty())
		m_lStates.front()->Update(_delta);
}

void StateManager::Render()
{
	if (!m_lStates.empty())
	{
		std::list< BaseState* >::iterator iter = (m_lStates.end());
		while (iter != m_lStates.begin())
			(*(--iter))->Render();
	}
}














