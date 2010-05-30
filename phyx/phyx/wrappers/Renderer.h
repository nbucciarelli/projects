/*
 *  Renderer.h
 *  Ants
 *
 *  Created by Kyle Rothermel on 4/11/09.
 *  Copyright 2009 Kyle Rothermel. All rights reserved.
 *
 *	Notes:
 *		- This game only uses a small amount of textures and therefore
 *		  they are not released until the renderer is shutdown.
 */
#ifndef RENDERER_H_
#define RENDERER_H_

#include <OpenGLES/EAGL.h>
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/EAGLDrawable.h>

#include <vector>
#include <string>

#include "../math/vec2.h"
#include "../math/vec4.h"
#include "../math/rect.h"

#include "../common/Globals.h"

class CRenderer
{
public:
	/*	Public Data Members		*/
	
protected:
	/*	Protected Data Members	*/
	
private:
	/*	Private Data Members	*/
	
	// Texture Data
	struct tTexture; // Forward declaration required.
	std::vector< tTexture >		m_vTextures;
	
	// Used to draw lines and rects
	TextureHandle				m_hPixel;
	
	//	Render Data
	GLuint						m_unViewRenderBuffer;
	GLuint						m_unViewFrameBuffer;
	GLint						m_nBackingWidth;
	GLint						m_nBackingHeight;
	EAGLContext*				m_pContext;
	
	// Class Instance
	static CRenderer			sm_Instance;
	
	// Structure Definitions
	struct tTGAHeader
	{
		unsigned char indentSize;
		unsigned char colorMapType;
		unsigned char imageType;
		unsigned short colorMapStart;
		unsigned short colorMapLength;
		unsigned char colormapBits;
		unsigned short xStart;
		unsigned short yStart;
		unsigned short width;
		unsigned short height;
		unsigned char numBits;
		unsigned char descriptor;
	};
	
	struct tTexture
	{
		GLuint handle;
		std::string fileName;
		short refCount;
		short width, height;
		short canvasWidth, canvasHeight;
		
		
		tTexture& operator=(const tTexture& C);
		
		tTexture() :
		handle(0),
		fileName(""),
		refCount(1),
		width(0),
		height(0),
		canvasWidth(0),
		canvasHeight(0)
		{}
	};
	
public:
	/*	Public Functions		*/
	
	/****************************************
	 *	Function:	GetInstance
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Return the instance of teh CRenderer
	 ****************************************/
	static CRenderer* GetInstance()	{ return &sm_Instance; }
	
	/****************************************
	 *	Function:	Init
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Initialize the CRenderer class.
	 ****************************************/
	void Init(GLuint _viewRenderBuffer, GLuint _viewFrameBuffer, GLint _backingWidth, GLint _backingHeight, EAGLContext* _context);
	
	/****************************************
	 *	Function:	Shutodown
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Shutdown the CRenderer class.
	 ****************************************/
	void Shutdown(void);
	
	/****************************************
	 *	Function:	Clear
	 *	Created:	[KR] May 29, 2009
	 *	Purpose:	Remove all textures
	 ****************************************/
	void Clear(void);
	
	/****************************************
	 *	Function:	LoadTexture
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Load a texture given a FileName and return a handle.
	 ****************************************/
	TextureHandle LoadTexture(const char* _fileName, short _width, short _height);
	
	/****************************************
	 *	Function:	ReleaseTexture
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Release a texture, delete if not needed anymore.
	 ****************************************/
	void ReleaseTexture(TextureHandle& _handle);
	
	/****************************************
	 *	Function:	ForceReleaseTexture
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Force a texture to be deleted.
	 ****************************************/
	void ForceReleaseTexture(TextureHandle& _handle);
	
	/****************************************
	 *	Function:	Begin
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Prep the surface for drawing.
	 ****************************************/
	void Begin(void);
	
	/****************************************
	 *	Function:	End
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Present the drawn surface.
	 ****************************************/
	void End(void);
	
	/****************************************
	 *	Function:	DrawTexture
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	Draw a texture to the screen.
	 ****************************************/
	void DrawTexture(TextureHandle _handle, const vec2& _pos, bool _centered = true, const vec2& _scale = vec2(1.0f, 1.0f),
					 const vec2& _rotOrigin = vec2(0.0f, 0.0f), float _rotMagnitude = 0.0f, const rect& _crop = rect::emptyRect(),
					 const vec4& _color = vec4(1.0f, 1.0f, 1.0f, 1.0f));
	
	/****************************************
	 *	Function:	DrawLine
	 *	Purpose:	Draw a line from one point to another.
	 *	Notes:		Only draws horizontal or verticle lines.
	 ****************************************/
	void DrawLine(const vec2& _v1, const vec2& _v2, const vec4& _color = vec4(1.0f, 1.0f, 1.0f, 1.0f));
	
	/****************************************
	 *	Function:	DrawRectSolid
	 *	Purpose:	Draw a rect, filled in.
	 ****************************************/
	void DrawRectSolid(const vec2& _topLeft, const vec2& _bottomRight, const vec4& _color = vec4(1.0f, 1.0f, 1.0f, 1.0f));
	
	/****************************************
	 *	Function:	DrawRect
	 *	Purpose:	Draw a outline of a rect.
	 ****************************************/
	void DrawRect(const vec2& _topLeft, const vec2& _bottomRight, unsigned _lineWidth = 1, const vec4& _color = vec4(1.0f, 1.0f, 1.0f, 1.0f));
	
protected:
	/*	Protected Functions		*/
	
private:
	/*	Private Functions		*/
	
	/****************************************
	 *	Function:	Constructor
	 *	Created:	[KR] April 11, 2009
	 ****************************************/
	CRenderer();
	
	/****************************************
	 *	Function:	Destructor
	 *	Created:	[KR] April 11, 2009
	 ****************************************/
	~CRenderer();
	
	/****************************************
	 *	Function:	DecodeTGA
	 *	Created:	[KR] April 11, 2009
	 *	Purpose:	
	 ****************************************/
	GLbyte* DecodeTGA(const char* _fileName, short& _canvasWidth, short& _canvasHeight);
	
	// Disabled Functions
	CRenderer(const CRenderer&);
	CRenderer& operator=(const CRenderer&);
};

static CRenderer * const _pRenderer = CRenderer::GetInstance();

#endif
