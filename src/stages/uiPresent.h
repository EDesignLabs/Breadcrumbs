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
#include "image.h"
#include "text.h"


class uiPresent {
	
public:
    
    uiPresent();
    ~uiPresent();
    
    void update();
    void draw(ofTrueTypeFont& basicFont);
    
    //tracking touch events
    void touchingDown(ofTouchEventArgs &touch);
    void touchingMove(ofTouchEventArgs &touch);
    void touchingUp(ofTouchEventArgs &touch);
    void doubleTap(ofTouchEventArgs &touch);
    void exit();
    
    void playData();
    void setPoints(vector <drawing> theDrawings, vector<flagState> theFlagStates);
    
    
    //how initial spots are drawn
    drawing thisDrawing;

    //This is the drawing that is tracked and then pushed on the stack
    vector <ofPoint> currentDrawing;
    vector <drawing> markerThese;
    
    vector <drawing> drawThese;
    ofColor          markerColor;
    
    int              startTime;
    int              endTime;
    
    //uiPresent
    button*          scrubBox;
    ofPoint*         scrubLocation;
    ofPoint          scrubPos;
    vector <ofPoint> scrubFeedback;
    
    
    //for flagging process
    vector<flagState> theFlagStates;
    
    //for playback and leaving reflections
    button*         playPauseButton;
    button*         markerButton;
    bool*           markerButtonSelected;
    
    //shows where pointer last left
    button*          currentPos;
    
    //used for playback
    int           currentTime;
    int           previousTime;
    
    
};

#endif
