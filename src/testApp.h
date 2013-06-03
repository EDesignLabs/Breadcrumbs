#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"

//For retina display
#include "ofxEasyRetina.h"
#include "ofxiOSEAGLView+retinaPatch.h"
#include "ofSwipeGestureRecognizer.h"


#include "nav.h"

class testApp : public ofxiPhoneApp{
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);

        nav     theNav;
    
        ofTrueTypeFont verdana12;
        ofTrueTypeFont verdana16;
        ofTrueTypeFont verdana22;
    
        char eventString[255];
    
        //declare an ofxEasyRetina instance
        ofxEasyRetina retina;

    
        //to identify specific  swipe gestures
        ofSwipeGestureRecognizer      *recogSwipe;
        int            section;


};


