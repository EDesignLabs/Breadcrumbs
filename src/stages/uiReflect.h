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

#include "ofxXmlSettings.h"
#include "xmlParty.h"

#include "ofxRetinaTrueTypeFont.h"

class uiReflect {
	
	public:
    
        uiReflect();
        ~uiReflect();
    
        void setPoints(vector <drawing> theDrawings);
		void update();
		void draw(ofxRetinaTrueTypeFont& quicksandBold60, ofxRetinaTrueTypeFont& quicksandBold36, ofxRetinaTrueTypeFont& quicksandBook36, bool loadedImage, ofImage& grid);
    
        void checkFlags();
        void checkSavedFlags();
    
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
        flagState         theFlagState;
    
//-----------------------------------------------
//for playback and leaving reflections
        button*         playPauseButton;
        button*         flagButton;
        button*         questionButton;
        ofImage*        FAQ;

//-----------------------------------------------
//shows where pointer last left
        button*          currentPos;
    
//-----------------------------------------------
//used for playback
        int           currentTime;
        int           previousTime;
    
    
};

#endif
