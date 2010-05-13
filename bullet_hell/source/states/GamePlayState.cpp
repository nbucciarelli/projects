/*
 *  GamePlayState.cpp
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "GamePlayState.h"

#include "Phyx/phyx.h"

#include "../common/Globals.h"

// Objects
#include "../objects/DPad.h"
#include "../objects/Avatar.h"

#define HOME_POSITION vec2( 50.0f, 320.0f - 50.0f )

GamePlayState::GamePlayState()
{
}

GamePlayState::~GamePlayState()
{
}

void GamePlayState::Enter()
{
	m_Avatar = new Avatar();
	m_DPad = new DPad();
	Phyx->Add( m_DPad, OP_UPDATE );
	
	Phyx->Add( m_Avatar, OP_UPDATE );
}

void GamePlayState::Exit()
{
}

void GamePlayState::Update(float _delta)
{
	vec2 temp;
	temp = m_Avatar->GetPosition() + ((m_DPad->GetPosition() - HOME_POSITION) / 3);
	m_Avatar->SetPosition(temp);	
}

void GamePlayState::Render()
{
}