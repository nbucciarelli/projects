/*
 *  Renderer.cpp
 *  Ants
 *
 *  Created by Kyle Rothermel on 4/11/09.
 *  Copyright 2009 Kyle Rothermel. All rights reserved.
 *
 */
#include "Renderer.h"

#include <cmath>
#include <algorithm>
#include <fstream>

#include "../common/alg.h"
#include "../common/Logger.h"

CRenderer CRenderer::sm_Instance;

/* Public Functions	*/
CRenderer::tTexture& CRenderer::tTexture::operator=(const CRenderer::tTexture& _t)
{
	handle = _t.handle;
	fileName = _t.fileName;
	refCount = _t.refCount;
	width = _t.width;
	height = _t.height;
	canvasWidth = _t.canvasWidth;
	canvasHeight = _t.canvasHeight;
	
	return *this;
}

CRenderer::CRenderer() : 
m_vTextures(),
m_hPixel(-1),
m_unViewRenderBuffer(0),
m_unViewFrameBuffer(0),
m_nBackingWidth(-1),
m_nBackingHeight(-1),
m_pContext(NULL)
{	}

CRenderer::~CRenderer()
{
	Shutdown();
}

void CRenderer::Init(GLuint _viewRenderBuffer, GLuint _viewFrameBuffer, GLint _backingWidth, GLint _backingHeight, EAGLContext* _context)
{	
	// Init variables.
	m_unViewRenderBuffer = _viewRenderBuffer;
	m_unViewFrameBuffer = _viewFrameBuffer;
	m_nBackingWidth = _backingWidth;
	m_nBackingHeight = _backingHeight;
	m_pContext = _context;
	
	// Init openGL
    [EAGLContext setCurrentContext:m_pContext];
    
    glBindFramebufferOES(GL_FRAMEBUFFER_OES, m_unViewFrameBuffer);
    glViewport(0, 0, m_nBackingWidth, m_nBackingHeight);
	
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, m_unViewRenderBuffer);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Default  -  glOrthof(-1.0f, 1.0f, -1.5f, 1.5f, -1.0f, 1.0f);
	glOrthof(-160.0f, 160.0f, -240.0f, 240.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
	
    glEnableClientState(GL_VERTEX_ARRAY);
    //glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_COLOR_MATERIAL);
    
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	
	
	// Load the pixel id
	m_hPixel = LoadTexture("pixel.tga", 1, 1);
}

void CRenderer::Shutdown(void)
{
	Clear();
}

void CRenderer::Clear()
{
	for (int i = 0; i < m_vTextures.size(); ++i)
		ForceReleaseTexture(i);
	m_vTextures.clear();
}

TextureHandle CRenderer::LoadTexture(const char* _fileName, short _width, short _height)
{
	// Find the index.
	int index = -1;
	for (unsigned i = 0; i < m_vTextures.size(); ++i)
	{
		if (m_vTextures[i].refCount == 0)
			index = i;
		if (strcmp(_fileName, m_vTextures[i].fileName.c_str()) == 0)
		{
			m_vTextures[i].refCount++;
			return i;
		}
	}
	
	// Set up image data
	tTexture tex;
	tex.fileName = _fileName;
	tex.refCount = 1;
	
	// Decode the texture file
	GLbyte* data = DecodeTGA( _fileName, tex.canvasWidth, tex.canvasHeight );
	if ( data == NULL )
	{
		return -1;
	}
	
	tex.width = ( _width != -1 ) ? _width : tex.canvasWidth;
	tex.height = ( _height != -1 ) ? _height : tex.canvasHeight;
	
	// Generate texture
	glGenTextures( 1, &tex.handle );
	
	// put texture into the vector.
	if ( index == -1 )
	{
		// Not +1 because it is before the push back.
		index = m_vTextures.size();
		m_vTextures.push_back(tex);
	}
	else
		m_vTextures[index] = tex;
	
	// Load image with openGL
	
	glBindTexture(GL_TEXTURE_2D, tex.handle);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex.canvasWidth, tex.canvasHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	
	free(data);
	
	return index;
}

void CRenderer::ReleaseTexture(TextureHandle& _handle)
{
	if (_handle != -1)
	{
		m_vTextures[_handle].refCount--;
		if (m_vTextures[_handle].refCount == 0)
		{
			m_vTextures[_handle].fileName = "";
			glDeleteTextures(1, &m_vTextures[_handle].handle);
		}
		_handle = -1;
	}
}

void CRenderer::ForceReleaseTexture(TextureHandle& _handle)
{
	if (_handle != -1)
	{
		m_vTextures[_handle].refCount = 1;
		ReleaseTexture(_handle);
		_handle = -1;
	}
}

void CRenderer::Begin(void)
{	
    glClear(GL_COLOR_BUFFER_BIT);
	
	glLoadIdentity();
	glTranslatef(160.0f, 240.0f, 0.0f);
	glRotatef(270.0f, 0.0f, 0.0f, 1.0f);
	glScalef(1.0f, -1.0f, 1.0f);
}

void CRenderer::End(void)
{
	[m_pContext presentRenderbuffer:GL_RENDERBUFFER_OES];
}

void CRenderer::DrawTexture(TextureHandle _handle, const vec2& _pos, bool _centered, const vec2& _scale, 
		const vec2& _rotOrigin, float _rotMagnitude, const rect& _crop, const vec4& _color)
{
	if (_handle == -1)
	{
		logger->log( "Failed to render a texture with id -1.", WARNING );
		return;
	}
	
	// Get a pointer to the texture to draw
	tTexture* tex = &m_vTextures[_handle];
	
	// Bind the texture to be drawn
	glBindTexture(GL_TEXTURE_2D, tex->handle);
	
	// Set up targets tex coords
	GLfloat* texCoords;
	int width;
	int height;
	if (_crop == rect::emptyRect())
	{
		width = tex->width;
		height = tex->height;
		float xTex = width / static_cast<float>(tex->canvasWidth);
		float yTex = height / static_cast<float>(tex->canvasHeight);
		GLfloat tmpTexCoords[] = {
			0, 0,
			xTex, 0,
			0, yTex,
			xTex, yTex
		};
		texCoords = tmpTexCoords;
	}
	else
	{
		width = _crop.right - _crop.left;
		height = _crop.bottom - _crop.top;
		float leftTex = _crop.left / static_cast<float>(tex->canvasWidth);
		float topTex = _crop.top / static_cast<float>(tex->canvasHeight);
		float rightTex = _crop.right / static_cast<float>(tex->canvasWidth);
		float bottomTex = _crop.bottom / static_cast<float>(tex->canvasHeight);
		GLfloat tmpTexCoords[] = {
			leftTex, bottomTex,					// bottom left
			rightTex, bottomTex,				// bottom right
			leftTex, topTex,					// top left
			rightTex, topTex					// top right
		};
		texCoords = tmpTexCoords;
	}
	
	// Set up the targets verts
	float xVert = width * _scale.x * .5f;
	float yVert = height * _scale.y * .5f;
	GLfloat verts[] = {
		-xVert, -yVert,
		xVert, -yVert,
		-xVert, yVert,
		xVert, yVert
	};
	
	// Save the matrix
	glPushMatrix();
	{
		// Color
		glColor4f(_color.r, _color.g, _color.b, _color.a);
		// If we aren't centered then the lower left is the 0, 0 point of square
		if (!_centered)
		{
			glTranslatef(width * _scale.x * .5f, height * _scale.y * .5f, 0.0f);
		}
		
		// Translate
		glTranslatef(_pos.x, _pos.y, 0.0f);
		
		// Don't handle rotation if we aren't going to rotate
		if (_rotMagnitude != 0.0f)
		{
			glRotatef(_rotMagnitude, 0.0f, 0.0f, 1.0f);
		}
		
		// Matrix is set up appropriately lets draw.
		glVertexPointer(2, GL_FLOAT, 0, verts);
		glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	}
	glPopMatrix();
}


void CRenderer::DrawLine(const vec2& _v1, const vec2& _v2, const vec4& _color)
{
	// only draw if its horizontal or verticle
	if (_v1.x == _v2.x || _v1.y == _v2.y)
	{
		DrawTexture(m_hPixel, vec2((_v1.x < _v2.x) ? _v1.x : _v2.x, (_v1.y <  _v2.y) ? _v1.y : _v2.y), false, 
					vec2(std::max(abs(_v2.x - _v1.x), 1), std::max(abs(_v2.y - _v1.y), 1)), vec2(0.0f, 0.0f), 0.0f, 
					rect::emptyRect(), _color);
	}
}

void CRenderer::DrawRectSolid(const vec2& _topLeft, const vec2& _bottomRight, const vec4& _color)
{
}

void CRenderer::DrawRect(const vec2& _topLeft, const vec2& _bottomRight, unsigned _lineWidth, const vec4& _color)
{
}

	/* Protected Functions	*/

	/* Private Functions	*/

GLbyte* CRenderer::DecodeTGA(const char* _fileName, short& _canvasWidth, short& _canvasHeight)
{
	std::ifstream fin(_GetFilePathGivenCStr(_fileName), std::ios::binary);
	if (!fin.is_open())
	{
		char buffer[64];
		sprintf( buffer, "Failed to open file in CRenderer::DecodeTGA _fileName: %s, absolute path: %s", _fileName, _GetFilePathGivenCStr(_fileName) );
		logger->log( buffer, ERROR );
		return NULL;
	}
	
	tTGAHeader tgaHeader;
	
	fin.read((char*)&tgaHeader.indentSize, 1);
	fin.read((char*)&tgaHeader.colorMapType, 1);
	fin.read((char*)&tgaHeader.imageType, 1);
	fin.read((char*)&tgaHeader.colorMapStart, 2);
	fin.read((char*)&tgaHeader.colorMapLength, 2);
	fin.read((char*)&tgaHeader.colormapBits, 1);
	fin.read((char*)&tgaHeader.xStart, 2);
	fin.read((char*)&tgaHeader.yStart, 2);
	fin.read((char*)&tgaHeader.width, 2);
	fin.read((char*)&tgaHeader.height, 2);
	fin.read((char*)&tgaHeader.numBits, 1);
	fin.read((char*)&tgaHeader.descriptor, 1);
	
	// not using pallets
	if (tgaHeader.colorMapType != 0) return NULL;
	// not using rle
	// type of image 0=none,1=indexed,2=rgb,3=grey,+8=rle packed
	if (tgaHeader.imageType != 2 && tgaHeader.imageType != 10) return NULL;
	// only load 32 bit tgas for now
	if (tgaHeader.numBits != 32) return NULL;
	// a targa we can load has been verified
	// set width and height
	_canvasWidth = tgaHeader.width;
	_canvasHeight = tgaHeader.height;
	// allocate room for the raw data
	GLbyte* pData = static_cast<GLbyte*>( malloc(tgaHeader.width * tgaHeader.height * ((tgaHeader.numBits)/8)) );
	if (tgaHeader.imageType == 2) // image type 2 means its raw data
	{
		fin.read((char*)pData, tgaHeader.width * tgaHeader.height * ((tgaHeader.numBits)/8));
	}
	else if (tgaHeader.imageType == 10) // image type 10 means its rle'd
	{
		// Counter to keep track of when we are done.
        int numPixelsRead = 0;
        // Char used for packet header
        unsigned char packetHeader;
        unsigned pixelColor;
        while (numPixelsRead < tgaHeader.width * tgaHeader.height)
        {
            fin.read((char*)&packetHeader, sizeof(char));
            // A runlength encoded packet
            if (packetHeader & 128)
            {
                fin.read((char*)&pixelColor, sizeof(unsigned));
                for (int i = 0; i < (packetHeader & 127) + 1; ++i)
                {
                    pData[(numPixelsRead * 4) + (i * 4) + 0] = (pixelColor & 255);
                    pData[(numPixelsRead * 4) + (i * 4) + 1] = ((pixelColor & (255 << 8)) >> 8);
					pData[(numPixelsRead * 4) + (i * 4) + 2] = ((pixelColor & (255 << 16)) >> 16);
					pData[(numPixelsRead * 4) + (i * 4) + 3] = ((pixelColor & (255 << 24)) >> 24);
				}
				numPixelsRead += (packetHeader & 127) + 1;
			}
			// A raw packet.
			else
			{
				for (int i = 0; i < (packetHeader & 127) + 1; ++i)
				{
					fin.read((char*)&pixelColor, sizeof(unsigned));
					
					pData[(numPixelsRead * 4) + 0] = (pixelColor & 255);
					pData[(numPixelsRead * 4) + 1] = ((pixelColor & (255 << 8)) >> 8);
					pData[(numPixelsRead * 4) + 2] = ((pixelColor & (255 << 16)) >> 16);
					pData[(numPixelsRead * 4) + 3] = ((pixelColor & (255 << 24)) >> 24);
					
					numPixelsRead++;
				}
			}
		}
	}
	
	return pData;
}




