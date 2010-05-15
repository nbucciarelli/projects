//
//  Weapon.mm
//  bullet_hell
//
//  Created by jamby on 5/14/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#include "Weapon.h"
#include "Avatar.h"
#include "Bullet.h"

#include "../common/Globals.h"
#include "../common/EventIds.h"

Weapon::Weapon() : Entity()
{
	m_pParent = NULL;
	SetType(PISTOL);
}

Weapon::~Weapon()
{

}

void Weapon::Update(float _delta)
{

}

void Weapon::SetType(int nType)
{
	m_nType = nType;
	
	switch(m_nType)
	{
		case PISTOL:
			m_fROF = 1.5f;
			break;
		case SHOTGUN:
			break;
		case BURST_RIFLE:
			break;
		case AUTO_RIFLE:
			break;
		default:
			break;
	}
}