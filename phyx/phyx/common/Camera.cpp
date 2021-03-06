/*
 *  Camera.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 4/18/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Camera.h"

#include "Globals.h"
#include "../objects/Entity.h"

Camera::Camera(Entity* _entity, rect _cameraBounds, rect _worldBounds) :
	m_pEntity( _entity ),
	m_vPosition( 0.0f, 0.0f),
	m_rCameraBounds( _cameraBounds ), 
	m_rWorldBounds( _worldBounds )
{
}

Camera::~Camera()
{
}

void Camera::Attach( Entity* _entity )
{
	m_pEntity = _entity;
}

void Camera::SetWorldBounds( rect& _worldBounds )
{
	m_rWorldBounds = _worldBounds;
}

void Camera::Update(float _delta)
{
	float relativePosX = m_pEntity->GetPosition().x - m_vPosition.x - ( SCREEN_WIDTH / 2 );
	float relativePosY = m_pEntity->GetPosition().y - m_vPosition.y - ( SCREEN_HEIGHT / 2 );
	
	// Camera needs to move right?
	if (relativePosX > m_rCameraBounds.right)
		m_vPosition.x = m_pEntity->GetPosition().x - ( ( SCREEN_WIDTH / 2 ) + m_rCameraBounds.right );
	else if (relativePosX < m_rCameraBounds.left)
		m_vPosition.x = m_pEntity->GetPosition().x - ( ( SCREEN_WIDTH / 2 ) + m_rCameraBounds.left );
	if (relativePosY > m_rCameraBounds.bottom)
		m_vPosition.y = m_pEntity->GetPosition().y - ( ( SCREEN_HEIGHT / 2 ) + m_rCameraBounds.bottom );
	else if (relativePosY < m_rCameraBounds.top)
		m_vPosition.y = m_pEntity->GetPosition().y - ( ( SCREEN_HEIGHT / 2 ) + m_rCameraBounds.top );
	
	// Cap to world bounds
	if (m_vPosition.x > m_rWorldBounds.right - SCREEN_WIDTH)
		m_vPosition.x = m_rWorldBounds.right - SCREEN_WIDTH;
	else if (m_vPosition.x < m_rWorldBounds.left)
		m_vPosition.x = m_rWorldBounds.left;
	if (m_vPosition.y > m_rWorldBounds.bottom - SCREEN_HEIGHT)
		m_vPosition.y = m_rWorldBounds.bottom - SCREEN_HEIGHT;
	else if (m_vPosition.y < m_rWorldBounds.top)
		m_vPosition.y = m_rWorldBounds.top;
}






























