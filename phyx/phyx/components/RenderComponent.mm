/*
 *  RenderComponent.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 5/2/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "RenderComponent.h"

#include "../wrappers/Renderer.h"
#include "../phyx.h"
#include "../objects/Entity.h"

RenderComponent::RenderComponent(Entity* _controlledEntity, const char* _textureName, short _texWidth, short _texHeight, bool _drawCentered) :
	BaseComponent( _controlledEntity ),
	m_bDrawCentered( _drawCentered )
{
	m_thTextureHandle = _pRenderer->LoadTexture( _textureName, _texWidth, _texHeight);
}

RenderComponent::~RenderComponent()
{
}

void RenderComponent::Update( float _delta )
{
	std::string scaleStr("scale");
	std::string rotMagnitudeStr("rotMagnitude");
	std::string rotOriginStr("rotOrigin");
	std::string cropStr("crop");
	std::string redStr("red");
	std::string greenStr("green");
	std::string blueStr("blue");
	std::string alphaStr("alpha");
	const vec2 * const scale = Phyx->GetAttr< vec2 >( (PhyxObject*)m_pControlledEntity, scaleStr );
	const float * const rotMagnitude = Phyx->GetAttr< float >( (PhyxObject*)m_pControlledEntity,  rotMagnitudeStr);
	const vec2 * const rotOrigin = Phyx->GetAttr< vec2 >( (PhyxObject*)m_pControlledEntity, rotOriginStr );
	const rect * const crop = Phyx->GetAttr< rect >( (PhyxObject*)m_pControlledEntity, cropStr );
	const float * const red = Phyx->GetAttr< float >( (PhyxObject*)m_pControlledEntity, redStr );
	const float * const green = Phyx->GetAttr< float >( (PhyxObject*)m_pControlledEntity, greenStr );
	const float * const blue = Phyx->GetAttr< float >( (PhyxObject*)m_pControlledEntity, blueStr );
	const float * const alpha = Phyx->GetAttr< float >( (PhyxObject*)m_pControlledEntity, alphaStr );
	_pRenderer->DrawTexture(m_thTextureHandle, 
							m_pControlledEntity->GetPosition(), 
							m_bDrawCentered,
							(scale != NULL) ? *scale : vec2(1.0f, 1.0f),
							(rotMagnitude != NULL) ? *rotOrigin : vec2(0.0f, 0.0f),
							(rotMagnitude != NULL) ? *rotMagnitude : 0.0f,
							(crop != NULL) ? *crop : rect::emptyRect(),
							(red != NULL) ? *red : 1.0f,
							(green != NULL) ? *green : 1.0f,
							(blue != NULL) ? *blue : 1.0f,
							(alpha != NULL) ? *alpha : 1.0f
							);
}






