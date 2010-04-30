/*
 *  MenuState.cpp
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "MenuState.h"

#include "phyx/wrappers/Renderer.h"
#include "phyx/math/vec2.h"
#include "phyx/phyx.h"

MenuState::MenuState()
{
}

MenuState::~MenuState()
{
}

void MenuState::Enter()
{
	m_thBackGround = _pRenderer->LoadTexture("precision.tga", 480, 320);
}

void MenuState::Exit()
{
}

void MenuState::Update(float _delta)
{
}

void MenuState::Render()
{
	_pRenderer->DrawTexture(m_thBackGround, vec2(0, 0), true, vec2(1.0, 1.0));
}