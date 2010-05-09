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

GamePlayState::GamePlayState()
{
}

GamePlayState::~GamePlayState()
{
}

void GamePlayState::Enter()
{
	Phyx->Add( new DPad(), OP_UPDATE );
}

void GamePlayState::Exit()
{
}

void GamePlayState::Update(float _delta)
{
}

void GamePlayState::Render()
{
}