/*
 *  Avatar.cpp
 *  bullet_hell
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Avatar.h"
#include "Weapon.h"

#include "phyx/managers/EventManager.h"
#include "phyx/components/RenderComponent.h"
#include "phyx/math/vec2.h"
#include "phyx/phyx.h"

#include "../common/Globals.h"
#include "../common/EventIds.h"

Avatar::Avatar() : Entity()
{
	m_vPosition = vec2( 240.0f, 160.0f );
	std::string scaleStr( "scale" );
	Phyx->SetAttr< vec2 >( this, scaleStr, vec2( 4.0f, 4.0f ) );
	Phyx->Add( new RenderComponent( this, "tempavatar.tga", 16, 16, true ), OP_UI );
	m_pWeapon = new Weapon();
	m_pWeapon->SetParent(this);
}

Avatar::~Avatar()
{

}

void Avatar::Update(float _delta)
{
	// These numbers will be changed when the avatar changes. - JH
	if(m_vPosition.x <= 25.0f)
		m_vPosition.x = 25.0f;
	
	if(m_vPosition.x >= 455.0f)
		m_vPosition.x = 455.0f;
	
	if(m_vPosition.y <= 25.0f)
		m_vPosition.y = 25.0f;

	if(m_vPosition.y >= 295.0f)
		m_vPosition.y = 295.0f;
}







