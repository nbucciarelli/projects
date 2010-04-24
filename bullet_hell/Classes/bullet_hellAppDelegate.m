//
//  bullet_hellAppDelegate.m
//  bullet_hell
//
//  Created by Kyle Rothermel on 2/16/10.
//  Copyright __MyCompanyName__ 2010. All rights reserved.
//

#import "bullet_hellAppDelegate.h"
#import "EAGLView.h"

@implementation bullet_hellAppDelegate

@synthesize window;
@synthesize glView;

- (void)applicationDidFinishLaunching:(UIApplication *)application {
    
	glView.animationInterval = 1.0 / 60.0;
	[application setStatusBarHidden: YES animated: YES];
	[glView startAnimation];
}


- (void)applicationWillResignActive:(UIApplication *)application {
	glView.animationInterval = 1.0 / 5.0;
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
	glView.animationInterval = 1.0 / 60.0;
}


- (void)dealloc {
	[window release];
	[glView release];
	[super dealloc];
}

@end
