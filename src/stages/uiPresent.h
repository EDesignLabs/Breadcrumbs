/*
 *  uiPresent.h
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#ifndef _uiPresent
#define _uiPresent


#include "ofMain.h"

#include "button.h"
#include "drawing.h"
#include "flagState.h"

#include "ofxXmlSettings.h"
#include "xmlParty.h"

#include "ofxRetinaTrueTypeFont.h"

class uiPresent {
	
public:
    
    uiPresent();
    ~uiPresent();
    
    void update();
    void draw(ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36, bool loadedImage, ofImage& grid);
    
//-----------------------------------------------
//tracking touch events
    void touchingDown(ofTouchEventArgs &touch);
    void touchingMove(ofTouchEventArgs &touch);
    void touchingUp(ofTouchEventArgs &touch);
    void doubleTap(ofTouchEventArgs &touch);
    void exit();
    
    void playData();    
    
//-----------------------------------------------
//how initial spots are drawn
    
    drawing thisDrawing;

//-----------------------------------------------
//This is the drawing from Create
    
    vector <drawing> drawThese;

//-----------------------------------------------
//This is the drawing that is tracked and then pushed on the stack

    vector <ofPoint> currentDrawing;
    vector <drawing> markerThese;
    
    ofColor          markerColor;
    
    int              startTime;
    int              endTime;
    
//-----------------------------------------------
//uiPresent

    button           scrubBox;
    ofPoint          scrubLocation;
    ofPoint          scrubPos;
    vector <ofPoint> scrubFeedback;
    int              scrubWidth;
    int              scrubHeight;
    
    float            _srubBoxPosEnd;
    
    button*          leftSide;
    button*          rightSide;
    
    
//-----------------------------------------------
//for flagging process
    
    vector<flagState> theFlagStates;
    
//-----------------------------------------------
//for playback and leaving reflections
    
    button*         playPauseButton;
    button*         markerButton;
    button*         questionButton;
    ofImage*        FAQ;
    
//-----------------------------------------------
//shows where pointer last left

    button*          currentPos;
    
//-----------------------------------------------
//used for playback
    
    int           currentTime;
    int           previousTime;
    
//-----------------------------------------------
//for saving the performance

    ofxXmlSettings XMLOne;
    ofxXmlSettings XMLTwo;
    string messageOne;
    string messageTwo;
    
    int lastTagNumberDrawing;
    int lastTagNumberTouchPoint;
    int lastTagNumberFlagstate;
    
};

#endif
