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
#include "phyx/components/RenderTSComponent.h"
#include "phyx/common/Camera.h"

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
	Phyx->Add( new DPad(), OP_UPDATE );
	Avatar* avatar = new Avatar();
	Camera* cam = new Camera( avatar, rect( -75, 50, 75, -50 ), rect( 0, 320, 480 * 5, 0 ) );
	Phyx->Add( avatar, OP_UPDATE );
	Phyx->Add( cam, OP_UPDATE );
	Phyx->SetCamera( cam );
	Phyx->Add( new RenderTSComponent( "tm_faces.bin" ), OP_BACKGROUND );
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





























