/*
 *  ofxKCScreensGUI.cpp
 *  Kimchi and Chips' Screens GUI
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "ofxKCScreensGUI.h"

ofxKCScreensGUI::ofxKCScreensGUI(float x, float y, float width, float height)
{
	isMaximised = false;

	_x = x;
	_y = y;
	
	_width = width;
	_height = height;
	
	assetLoad();
}

bool ofxKCScreensGUI::doFullscreen()
{
	return mainScreen->hitMaximise(_mousex, _mousey);
}

void ofxKCScreensGUI::update()
{
	g_updateIsUserActive();
	
	if (!mainScreen->isFullscreen || g_isUserActive)
		ofShowCursor();
	else
		ofHideCursor();
}

void ofxKCScreensGUI::draw()
{
	mainScreen->draw();
}

//------------------------------------------------------------------------------------------------

void ofxKCScreensGUI::mouseMoved(int x, int y)
{
	if (mainScreen->isHit(x, y))
		mainScreen->mouseMoved(x, y);
	
	_mousex = x;
	_mousey = y;

	interfaceNudge();
}

void ofxKCScreensGUI::mouseDown(int x, int y)
{
	if (mainScreen->isHit(x, y))
		mainScreen->mouseDown(x, y);
	interfaceNudge();
}

void ofxKCScreensGUI::mouseReleased(int x, int y)
{
	if (mainScreen->hasCursorAttached)
		mainScreen->mouseReleased(x, y);
	
	interfaceNudge();
}

//------------------------------------------------------------------------------------------------
