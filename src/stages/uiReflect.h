/*
 *  uiReflect.h
 *
 *  Created by Ryan Raffa on 4/25/13.
 *
 */

#ifndef _uiReflect
#define _uiReflect


#include "ofMain.h"

#include "button.h"
#include "drawing.h"
#include "flagState.h"


class uiReflect {
	
	public:
    
        uiReflect();
        ~uiReflect();
    
        void setPoints(vector <drawing> theDrawings);
		void update();
		void draw(ofTrueTypeFont& basicFont);
		void draw(ofTrueTypeFont& basicFont, ofImage& questionImage);
    
        void checkFlags();

        //tracking touch events
        void touchingDown(ofTouchEventArgs &touch);
        void touchingMove(ofTouchEventArgs &touch);
        void touchingUp(ofTouchEventArgs &touch);
        void doubleTap(ofTouchEventArgs &touch);
        void exit();

        void playData();
    
        //This is the drawing that is tracked and then pushed on the stack
        vector <drawing> drawThese;
    
        int              startTime;
        int              endTime;
    
//-----------------------------------------------
//uiReflect
        button*          scrubBox;
        ofPoint*         scrubLocation;
        ofPoint          scrubPos;
        vector <ofPoint> scrubFeedback;
    
    
//-----------------------------------------------
//for flagging process
        vector<flagState> theFlagStates;
        flagState         theFlagState;
    
//-----------------------------------------------
//for playback and leaving reflections
        button*         playPauseButton;
        button*         flagButton;
    
//-----------------------------------------------
//shows where pointer last left
        button*          currentPos;
    
//-----------------------------------------------
//used for playback
        int           currentTime;
        int           previousTime;
    
    
};

#endif
