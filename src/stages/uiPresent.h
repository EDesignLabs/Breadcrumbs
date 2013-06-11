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

class uiPresent {
	
public:
    
    uiPresent();
    ~uiPresent();
    
    void update();
    void draw(ofTrueTypeFont& basicFont);
    void draw(ofTrueTypeFont& basicFont, ofImage& questionImage);
    
//-----------------------------------------------
//tracking touch events
    void touchingDown(ofTouchEventArgs &touch);
    void touchingMove(ofTouchEventArgs &touch);
    void touchingUp(ofTouchEventArgs &touch);
    void doubleTap(ofTouchEventArgs &touch);
    void exit();
    
    void playData();
    void setPoints(vector <drawing> theDrawings, vector<flagState> theFlagStates);
    
    
//-----------------------------------------------
//XML

    void xmlSetupThang(string iPhoneDocumentsDirectory, string xmlFileOne, string xmlFileTwo);
    void getXML (string xmlFileOne, string XMLFileTwo);
    void saveXML(string iPhoneDocumentsDirectory, string xmlFileOne, string xmlFileTwo);
    
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

    button*          scrubBox;
    ofPoint*         scrubLocation;
    ofPoint          scrubPos;
    vector <ofPoint> scrubFeedback;
    int              scrubWidth;
    
    button*          rightSide;
    
    
//-----------------------------------------------
//for flagging process
    
    vector<flagState> theFlagStates;
    
//-----------------------------------------------
//for playback and leaving reflections
    
    button*         playPauseButton;
    button*         markerButton;
    bool*           markerButtonSelected;
    
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
