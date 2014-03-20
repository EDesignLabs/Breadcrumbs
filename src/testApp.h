#pragma once

#include "ofMain.h"

#include "ofxiOS.h"
#include "ofxiOSExtras.h"

#include "ofxRetinaTrueTypeFont.h"

#include "ofxTextSuite.h"


//For retina display
#include "ofxEasyRetina.h"
#include "ofxiOSEAGLView+retinaPatch.h"
#include "ofSwipeGestureRecognizer.h"
#include "ofPanGestureRecognizer.h"

#include "xmlParty.h"
#include "ofxXmlSettings.h"

#include "nav.h"

class testApp : public ofxiOSApp{
	
    public:
        void setup();
        void update();
        void draw();
        void drawNewText();
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

        nav         theNav;
        xmlParty    theXMLParty;
    
        ofxRetinaTrueTypeFont quicksandBold60;
        ofxRetinaTrueTypeFont quicksandBold36;
        ofxRetinaTrueTypeFont quicksandBook36;
    
        char eventString[255];
    
//-----------------------------------------------
//declare an ofxEasyRetina instance

        ofxEasyRetina   retina;

    
//-----------------------------------------------
//to identify specific  swipe gestures

        int             section;
        string          direction;
    
//-----------------------------------------------
//XML file location

        string          iOSDocumentsDirectory;
    
    
//-----------------------------------------------
//Wrapping text
    
        ofxTextBlock       theTextWrap;

    
//-----------------------------------------------
//to identify specific pan gestures

        ofPanGestureRecognizer      *recogPan;

//-----------------------------------------------
//variables used by openFrameworks for pan

        ofPoint             pos;
        ofPoint             speed;
        float               angle;
        ofPoint             newLocation;
    
//-----------------------------------------------
//info coming from ofPanGestureRecognizer

        ofPoint             velocity;
        ofPoint             startLocation;
        ofPoint             currentLocation;
        ofPoint             endLocation;
        bool                panning;
    
    
    
//-----------------------------------------------
//for XML

        ofxXmlSettings      XMLOne;
        ofxXmlSettings      XMLTwo;

    

//-----------------------------------------------
//for XML
    
        string              userName;

    
//-----------------------------------------------
//for keyboard interaction
    
        ofxiPhoneKeyboard * keyboard;
//        ofxiPhoneKeyboard * keyboardTwo;

        button              editTextMathButton;
        button              saveNewText;
    
        //has the new text been saved
        bool                navStateNewTextWindow;
        bool                navStateNewTextSaved;

        //for submitting user name
        button              submitUserNameButton;

    
        //got to Breadcrumbs website
        button              goToURL;
    

};


