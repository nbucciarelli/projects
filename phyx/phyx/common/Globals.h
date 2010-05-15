/*
 *  typedefs.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _typedefs_h_
#define _typedefs_h_

// A typedef for texture handles
typedef int TextureHandle;

// A typedef for timer Handles
typedef int TimerHandle;

// A typedef for sound Handles
typedef int SoundHandle;

#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 480
#endif

#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 320
#endif

enum EVENT_PRIORITY
{
	EP_LOW,
	EP_MEDIUM,
	EP_HIGH
};

#endif