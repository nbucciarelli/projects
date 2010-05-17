//
//  Bullet.mm
//  bullet_hell
//
//  Created by jamby on 5/14/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#include "Bullet.h"
#include "Weapon.h"

#include "../common/Globals.h"
#include "../common/EventIds.h"

Bullet::Bullet() : Entity()
{
	m_pWeaponParent = NULL;
	m_vPosition = vec2(0.0f, 0.0f);
	m_nDamage = 0;
	m_fLifetime = 0.0f;
	m_vDirection = vec2(0.0f, 0.0f);
	m_bShot = false;
}

Bullet::~Bullet()
{
	
}

void Bullet::Update(float _delta)
{
	if(m_bShot)
	{
		m_fLifetime += _delta;
		// Interpolate from the bullet's position until you go to it's direction
		// point, then when it reaches it's direction point switch to interpolating
		// the opposite way except adding onto the position so it keeps going
		// past the direction point.
		//if(m_vPosition < m_vDirection)
		//{
			
		//}
		//else
		//{
			
		//}
		// ^^ This may not work if the direction is on the left side, thereby being
		// less than the position.

	}
	
	if(!m_bShot && !m_bBeenReset)
	{
		ResetBullet();
		m_bBeenReset = true;
	}
}

void Bullet::ResetBullet(void)
{
	switch(m_pWeaponParent->GetType())
	{
		case PISTOL:
			m_vPosition = vec2(0.0f, 0.0f);
			m_nDamage = 1;
			m_vDirection = vec2(0.0f, 0.0f);
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