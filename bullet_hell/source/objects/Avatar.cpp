/*
 *  Avatar.cpp
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Avatar.h"

#include "phyx/managers/EventManager.h"
#include "phyx/components/RenderComponent.h"
#include "phyx/math/vec2.h"
#include "phyx/phyx.h"

#include "../common/Globals.h"
#include "../common/EventIds.h"

Avatar::Avatar() : Entity()
{
	m_vPosition = vec2( 50.0f, 50.0f );
	std::string scaleStr( "scale" );
	Phyx->SetAttr< vec2 >( this, scaleStr, vec2( 4.0f, 4.0f ) );
	Phyx->Add( new RenderComponent( this, "tempavatar.tga", 16, 16, true ), OP_UI );
}

Avatar::~Avatar()
{

}

void Avatar::Update(float _delta)
{
	
}







