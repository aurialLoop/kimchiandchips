#ifndef _PCEncode
#define _PCEncode
/*
 *  PCEncode.h
 *  PCEncode
 *
 *  Created by Elliot Woods on 25/10/2009.
 *  Copyright 2009 Kimchi and Chips. All rights reserved.
 *
 */


#include "ofMain.h"
#include "PCconstants.h"
#include "scrTexture.h"
#include "PCConfig.h"

#include "scrTexture.h"

#include "PayloadBase.h"

class PCEncode : public PCConfig 
{
public:
	PCEncode(PayloadBase *payload, bool* boolProjectorMask);
	~PCEncode();
	
	int						getnProjectorPixels();
	int						getnScanFrames();
	int						getnScanFramesPerInterleave();
	int						getnScanDataFramesPerInterleave();
	int						getnCalibrationFrames();
	int						getnInterleaves();

	void					updateScanFrame(int iScanInterleaveFrame, int iInterleave);
	void					updateCalibrationFrame(int iCalibrationFrame);
	
	scrTexture				scrSend;
private:
	
	ofTexture				_texOutput;
	unsigned char *			_texCharOutput;
	
	PayloadBase				*_payload;
	
	bool *					_boolProjectorMask;
	
};


#endif

