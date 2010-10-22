#pragma once
/*
 *  scrHistograms.h
 *  pixel correlation
 *
 *  Created by Elliot Woods on 27/01/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "scrBase.h"

#include "Histogram.h"

class scrHistograms : public scrBase
{
public:
	scrHistograms(int iScreen, enumShowCursor showCursor, bool hasCursorEvents, int screenOrder, string caption);
	
	void						draw();
	void						draw(int x, int y, int width, int height);
	void						drawHistogram();
	
	void						addHistogram(Histogram &histogram);
	
	virtual void				mouseDown(float xX, float xY, int x, int y);

private:
	std::vector<Histogram*>	_vecHistograms;
};