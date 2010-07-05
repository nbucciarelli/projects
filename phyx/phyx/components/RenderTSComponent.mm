/*
 *  RenderTSComponent.cpp
 *  phyx
 *
 *  Created by Kyle Rothermel on 7/4/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "RenderTSComponent.h"

#include <fstream>

#include "../wrappers/Renderer.h"
#include "../common/Logger.h"
#include "../common/alg.h"
#include "../phyx.h"
#include "../common/Camera.h"

RenderTSComponent::RenderTSComponent(const char* _filePath) :
	BaseComponent( NULL )
{
	std::ifstream fin( _GetFilePathGivenCStr( _filePath ), std::ios::binary | std::ios::in );
	if ( !fin.is_open() )
	{
		char buffer[64];
		sprintf( buffer, "Failed to open file in RenderTSComponent::RenderTSComponent. _filePath: %s.", _filePath );
		logger->log( buffer, ERROR );
		return;
	}
	
	// Skip header data for now.
	fin.seekg( 8 );
	short filePathLen;
	fin.read( (char*)&filePathLen, 2 );
	char* filePath = new char[ filePathLen ];
	fin.read( filePath, filePathLen );
	fin.read( (char*)&m_nTileWidth, 4 );
	fin.read( (char*)&m_nTileHeight, 4 );
	fin.read( (char*)&m_nMapWidth, 4 );
	fin.read( (char*)&m_nMapHeight, 4 );
	
	m_thTextureHandle = _pRenderer->LoadTexture( filePath );
	m_pnTiles = new int[ m_nMapWidth * m_nMapHeight ];
	for ( int i = 0; i < m_nMapWidth * m_nMapHeight; ++i )
	{
		fin.read( (char*)&m_pnTiles[i], 4 );
	}
	
	delete[] filePath;
}

RenderTSComponent::~RenderTSComponent()
{
	delete[] m_pnTiles;
}

void RenderTSComponent::Update( float _delta )
{
	for( int i = 0; i < m_nMapWidth * m_nMapHeight; ++i )
	{
		// The crop parameter crops with the bottom left being 0, 0
		// Fix the hard-coded numbers here
		// Also potentially switch the renderer to use the top left of the texture as 0, 0 for cropping
		int tileX = ( m_pnTiles[ i ] % (256/32) ) * m_nTileWidth;
		int tileY = 224 - ( ( m_pnTiles[ i ] / (256/32) ) * m_nTileHeight );
		_pRenderer->DrawTexture(m_thTextureHandle,
								vec2( ( i % m_nMapWidth) * m_nTileWidth, ( ( i / m_nMapWidth ) + 1 ) * m_nTileHeight ) - Phyx->GetCamera()->GetPosition(),
								false,
								vec2(1.0f, 1.0f),
								vec2(0.0f, 0.0f),
								0.0f,
								rect(tileX, tileY, tileX + m_nTileWidth, tileY + m_nTileHeight) );
	}
}