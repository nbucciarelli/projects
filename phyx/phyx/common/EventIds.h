/*
 *  EventIds.h
 *  phyx
 *
 *  Created by Kyle Rothermel on 2/21/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef EVENTIDS_H_
#define EVENTIDS_H_

enum EVENTID
{
	NO_EVENT = 0,
	
	// Map Triggers
	FIRST_MAP_TRIGGER,
	COLLIDABLE_TILE,
	LAST_MAP_TRIGGER,
	MAP_RESIZE,
	
	// Input
	FIRST_INPUT_EVENT,
	TOUCHES_BEGAN,
	TOUCHES_MOVED,
	TOUCHES_ENDED,
	LAST_INPUT_EVENT,
	
	// Test events
	TEST_EVENT,
	
	// Max events.
	LAST_ENGINE_EVENT
};

#endif