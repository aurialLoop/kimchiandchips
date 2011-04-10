/*
 *  wdgCounter.cpp
 *  PC Encode
 *
 *  Created by Elliot Woods on 03/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "wdgCounter.h"

wdgCounter::wdgCounter(string caption,
		  int &myValue,
		  int myMax) :
wdgBase(caption),
_value(myValue)
{
	setMax(myMax);	
}

void wdgCounter::setMax(int myMax)
{
	int rowWidth = _width / (COUNTER_RADIUS*4);
	int rows = max((int)ceil(float(myMax) / float(rowWidth)),1);
	
	_height = 30+COUNTER_RADIUS*4*rows;
	_max = myMax;
}

void wdgCounter::draw()
{

	string numDisplay = ofToString(_value);
    if (_max > 0)
        numDisplay += "/" + ofToString(_max);
	
	ofPushStyle();
	ofSetColor(255, 255, 255);
	ofSetLineWidth(1);
	
	ofDrawBitmapString(caption + ":", _x, _y+10);
	ofDrawBitmapString(numDisplay, _x+_width - numDisplay.length()*8, _y+10);
	
	int row, col;
	int rowWidth = _width / (COUNTER_RADIUS*3);
	int maxCounters = max(_value,_max);
	
	for (int i=0; i < maxCounters; i++)
	{
		if (i>_value)
			ofNoFill();
		else
			ofFill();
		
		col = i % rowWidth;
		row = i / rowWidth;
		
		ofCircle(_x + col * COUNTER_RADIUS*3,
				 _y+15+COUNTER_RADIUS + row * COUNTER_RADIUS*3, COUNTER_RADIUS);
	}
	
	ofPopStyle();
}
