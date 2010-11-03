#ifndef _PCApp
#define _PCApp


#include "ofMain.h"

#include "ofxKCScreensGUI.h"

#include "PCconstants.h"
#include "PCManager.h"

#include "CorrelateMain.h"

//#include "PCConfig.h"
//#include "PCEncode.h"
//#include "PCDecode.h"
//#include "PCLogger.h"
//#include "PayloadGraycode.h"
//#include "PayloadBinary.h"

class PCApp : public ofBaseApp {

	public:
		PCApp();
		~PCApp();
	
		void setup();
		void update();
		void draw();
//		void drawStatus();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button); 
		void mouseReleased(int x, int y, int button);
		void mouseDown(int x, int y); // new function. is called whenever mouse is down / moved when down

		void windowResized(int w, int h);
	
	private:
		string				getDateString();
		
		PCManager			_scanner;

	
		ofxKCScreensGUI		*_screens;

		string				_strStatus;
		char				_strDebug[200];
		string				_strHistograms;
	

protected:
	
	//correlator
	CorrelateMain			_Correlator;
	
	//user interface
	wdgCounter				*_wdgFrameCounter;
	
	//calibration variables
	float					_screenDistance;
	float					_screenWidth, _screenHeight;
};

#endif