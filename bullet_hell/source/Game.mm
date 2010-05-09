/*
 *  Game.cpp
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Game.h"

// Managers
#include "phyx/phyx.h"
#include "phyx/managers/EntityManager.h"

#include "states/MenuState.h"
#include "common/Globals.h"

// Objects
#include "objects/DPad.h"

Game Game::sm_Instance;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	Phyx->Add( new DPad(), OP_UPDATE );
}

void Game::Shutdown()
{
}

void Game::Heartbeat()
{
	Update();
	Render();
}

void Game:: Update()
{
	Phyx->PreUpdate();
	
	Phyx->Update();
	
	Phyx->PostUpdate();
}

void Game::Render()
{
	Phyx->PreRender();
	
	Phyx->Render();
	
	Phyx->PostRender();
}





























