#pragma once
/*
 *  wdgBase.h
 *  PC Encode
 *
 *  Created by Elliot Woods on 02/11/2010.
 *  Copyright 2010 Kimchi and Chips. All rights reserved.
 *
 */

#include "ofMain.h"

class wdgBase
{
public:
	wdgBase(string _caption);

	virtual void	draw() = 0;
	
	virtual void	mouseDown(int x, int y) = 0;
	bool			isHit(int x, int y);
	
	void			setBounds(int x, int y, int width);
	
	const int		&height;
	string			caption;
	
protected:
	int				_x, _y;
	int				_width, _height;
};